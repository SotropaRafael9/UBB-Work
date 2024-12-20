							CraftFinan

1. Short description

Keeping track of your expenses can be tricky, that's why most people fail to do it. 
No one wants to continually have to deal with Excel papers, calculations, and other hassles. 
But what if someone would do all this meticulous work for you?
CraftFinan is your personal finance assistant, simplifying money management. 
Track your spending, set budgets, and gain control of your financial world. Create, view, and edit transactions with ease. 
Take charge of your money like a wizard with CraftFinan!

2. Domain details

Shortly, let's focus on the main subject, a transaction

Transaction: title, type,category, amount, timestamp

- title: represents a concise description of the transaction, will be chosen by the user;
- type: the transaction can either be an expense or an income;
- category: expenses can be of multiple types like: health, investments, groceries, transport etc. The user can choose the type of expense from a list of options, or can write himself one;
- amount: the amount of money of the expense, inserted by the user;
- timestamp: represents the day and the time that the transaction happened. It will be generated automatically at the point of adding a new transaction in the app.

3. How do we want to use this product?

- When using "CraftFinan", we want to be able to add a new expense (transaction) to our journal, whenever we make a relevant transaction that can
be either spending or receiving money. So, we are thinking of a button, which redirects to a
separate page. Here, we can enter all the necessary information for our story. We could also have the ballance of your wallet updated every time
a transaction is made.

- We want to have the option of listing all the registered transactions together.

- Due to haste or distraction, people could not complete all the fields of the transaction, like not having time to add a proper description or a title,
entered the wrong amount and so on. Reason why it is mandatory to give the user the possibility to modify the transactions.
We consider that a button for "update" is intuitive and by pressing it, the user will be redirected to a new page,
in the same manner as for the "add" option. Such a button will exist next to each item in the list.

- Because people sometimes would consider that they don't need a specific item in the expense list, or they created
something wrong it is necessary to give them the delete option. 
We would like to have a button, for "delete" action, next to each item in the list and a confirmation for
such an action, because that button may be pressed by accident or maybe the user just changes his mind.

4. How to we store our stories?

- We believe that the persistence is vital to our application, so we want it to be both connected to
a local database and a server. This would make "CrafterFinan" available online and offline too. 
For adding/updating/deleting a transaction we want to store the changes both ways, so they would be persisted on the
server and on the local database too.

- When the user is online, the data for listing our entities is taken from the
server (so updates are reflected immediately).

- When the user is offline, the temporary data is taken from the local database.

5. What happens if the user is offline?

- In this case, we want to develop an application which lets the user to add, remove and modify entries locally.
In this way, changes will persist only locally in the database. 

When the application is used offline, all the operations performed store the information locally:
-	the entities created are stored in the local database
-	the read operation is performed on the locally saved entities
-	the update operation goes for the locally saved entities
-	the delete operation is performed on the local database

- When the application goes back online, all the changes on the local database are transmitted to the server.
 
- As long as there is no internet connection, the notes are available only with the properties
previously saved in the database.