import multiprocessing
import random
import time

class LogEntry:
    def __init__(self, serial_number, from_account, to_account, amount):
        self.serial_number = serial_number
        self.from_account = from_account
        self.to_account = to_account
        self.amount = amount

    def __repr__(self):
        return f"Transfer #{self.serial_number}: {self.amount} from Account {self.from_account} to Account {self.to_account}"

class Account:
    def __init__(self, account_id, initial_balance):
        self.account_id = account_id
        # Shared balance and make sure is updated and synchronisted
        self.balance = multiprocessing.Value('d', initial_balance)  
        self.log = multiprocessing.Manager().list()  
        self.lock = multiprocessing.Lock()

class Bank:
    def __init__(self, num_accounts, initial_balance):
        self.accounts = [Account(i, initial_balance) for i in range(num_accounts)]
        self.serial_number = multiprocessing.Value('i', 0)  
        self.serial_lock = multiprocessing.Lock()  # Lock for serial number

    
    def generate_serial_number(self):
        with self.serial_lock:
            self.serial_number.value += 1
            return self.serial_number.value

    def transfer(self, from_account_id, to_account_id, amount):
        if from_account_id == to_account_id:
            return  

        # Ensure to lock accounts in a consistent order to avoid deadlocks
        acc1 = self.accounts[min(from_account_id, to_account_id)]
        acc2 = self.accounts[max(from_account_id, to_account_id)]

        with acc1.lock, acc2.lock:
            # perform the transfer if the balance allows
            if acc1.balance.value >= amount:
                acc1.balance.value -= amount
                acc2.balance.value += amount

                # log the transaction
                serial = self.generate_serial_number()
                log_entry = LogEntry(serial, from_account_id, to_account_id, amount)
                acc1.log.append(log_entry)
                acc2.log.append(log_entry)

    # Consistency check for account balances and logs
    def consistency_check(self):
        print("\nPerforming consistency check...")
        for account in self.accounts:
            with account.lock:
                balance_from_logs = 0
                for log in account.log:
                    if log.from_account == account.account_id:
                        balance_from_logs -= log.amount
                    elif log.to_account == account.account_id:
                        balance_from_logs += log.amount

                # Check if balance matches the sum from logs
                if balance_from_logs != account.balance.value:
                    print(f"Account {account.account_id}: Consistency error!")
                else:
                    print(f"Account {account.account_id}: Consistent.")

# Function for process to perform random transfers
def perform_random_transfers(bank, num_transfers, max_amount):
    num_accounts = len(bank.accounts)
    for _ in range(num_transfers):
        from_account_id = random.randint(0, num_accounts - 1)
        to_account_id = random.randint(0, num_accounts - 1)
        amount = random.uniform(1, max_amount)
        bank.transfer(from_account_id, to_account_id, amount)
        time.sleep(random.uniform(0.01, 0.05))  # Simulate delay between operations


if __name__ == "__main__":
    num_accounts = 5
    initial_balance = 1000
    num_processes = 4
    transfers_per_process = 20
    max_transfer_amount = 200

    # Create the bank with the given number of accounts
    bank = Bank(num_accounts, initial_balance)

    # Create and start processes to perform random transfers
    processes = []
    for _ in range(num_processes):
        p = multiprocessing.Process(target=perform_random_transfers, args=(bank, transfers_per_process, max_transfer_amount))
        processes.append(p)
        p.start()

    # Wait for all processes to finish
    for p in processes:
        p.join()

    # Perform final consistency check
    bank.consistency_check()

    # Print logs for each account
    for account in bank.accounts:
        print(f"\nAccount {account.account_id} log:")
        for entry in account.log:
            print(entry)