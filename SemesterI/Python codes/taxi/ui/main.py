from taxiService import TaxiService
from repository.repository import Repo
from ui import UI

repo = Repo()
number_of_taxis = int(input("Please enter the number of taxi cabs: "))

taxi_service = TaxiService(repo, number_of_taxis)

ui = UI(taxi_service)

ui.start()