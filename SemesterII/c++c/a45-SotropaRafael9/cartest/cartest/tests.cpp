#include "Repository.h"
#include "Tests.h"
#include <iostream>
#include <cassert>
    Test::Test() {

    }
    void  Test::testAdd() {
        Repo repo;
        Car car1("Fiat", "Bravo", 2007, "red");
        Car car2("Fiat", "Idea", 2003, "black");
        assert(repo.add(car1) == true);
        assert(repo.add(car1) == false); // Adding the same car should fail
        assert(repo.add(car2) == true);
    }

    void Test::testRemove() {
        Repo repo;
        Car car1("Fiat", "Bravo", 2007, "red");
        Car car2("Fiat", "Idea", 2003, "black");
        repo.add(car1);
        repo.add(car2);
        assert(repo.remove(car1) == true);
        assert(repo.remove(car1) == false); // Removing the same car should fail
    }

    void Test::testSortColour() {
        Repo repo;
        Car car1("Fiat", "Bravo", 2007, "red");
        Car car2("Fiat", "Idea", 2003, "black");
        Car car3("Audi", "A5", 2007, "blue");
        Car car4("BMV", "Coupe", 2013, "pink");
        Car car5("Ford", "Fiesta", 1976, "yellow");
        repo.add(car1);
        repo.add(car2);
        repo.add(car3);
        repo.add(car4);
        repo.add(car5);
        vector<Car> vintage_cars = repo.sortColour();
        assert(vintage_cars.size() == 1);
        assert(vintage_cars[0].GetColour() == "yellow");
    }

    void Test::testSortManufacturerandModel() {
        Repo repo;
        Car car1("Fiat", "Bravo", 2007, "red");
        Car car2("Fiat", "Idea", 2003, "black");
        Car car3("Audi", "A5", 2007, "blue");
        Car car4("BMV", "Coupe", 2013, "pink");
        Car car5("Ford", "Fiesta", 1976, "yellow");
        repo.add(car1);
        repo.add(car2);
        repo.add(car3);
        repo.add(car4);
        repo.add(car5);
        repo.sortManufacturerandModel();
        vector<Car> cars = repo.getCars();
        assert(cars.size() == 5);
        assert(cars[0].GetModel() == "Bravo");
        assert(cars[1].GetModel() == "Coupe");
        assert(cars[2].GetModel() == "Fiesta");
        assert(cars[3].GetModel() == "Idea");
        assert(cars[4].GetModel() == "A5");
    }

    void Test::run_all_test() {
        testAdd();
        testRemove();
        testSortColour();
        testSortManufacturerandModel();
        std::cout << "All tests passed!\n";
    }

