package view;
import controller.Controller;
import java.util.InputMismatchException;
import java.util.Scanner;
import model.Pomi;

public class View{

    private final Controller service;
    private static final Scanner console = new Scanner(System.in);

    public View(Controller srv)
    {
        this.service= srv;
    }
    private void Menu() {
        System.out.println("--------------------");
        System.out.println("1. Add pom");
        System.out.println("2. Remove pom");
        System.out.println("3. Print pomi");
        System.out.println("4. Print pomi that are greater that 3");
        System.out.println("5. Exit");
        System.out.println("--------------------");
    }
    private void addPomi() throws Exception {
        System.out.println("Please enter the type of the pom[ciresi, peri, meri]: ");
        String type = console.nextLine().toLowerCase();
        System.out.println("Please enter the age of the pom [>0]: ");
        int age = console.nextInt();

        this.service.addPomi(type, age);
        System.out.println("Your pom has been added successfully");

    }
    private void removePomi() {
        System.out.println("Please enter your index ");
        int index = console.nextInt();

        this.service.removePomi(index - 1);

        System.out.println("The pom with index " + index + " has been successfully removed.");
    }
    private void printPomi() throws Exception {
        Pomi[] pomii = this.service.getPomi();
        int counter = 0;
        for(Pomi pomi : pomii) {
            if(pomi != null) {
                System.out.println(++counter + ". " + pomi);
            }
        }
    }
    private void printFilteredPomi() throws Exception {
        Pomi[] pomii = this.service.getPomiFilteredByAge(3);
        int counter = 0;
        for (Pomi pomi : pomii) {
            if (pomi != null) {
                System.out.println(++counter + ". " + pomi.toString());
            }
        }
    }
    public void run() {
        System.out.println("Hello user");

        while(true) {
            this.Menu();
            try {
                 int option;
                 System.out.println("Please select what do you want to do: ");
                 option = console.nextInt();
                 console.nextLine();
                 switch(option) {
                     case 5:
                         System.out.println("Goodbye!");
                         return;
                     case 1:
                         this.addPomi();
                         break;
                     case 2:
                         this.removePomi();
                         break;
                     case 3:
                         this.printPomi();
                         break;
                     case 4:
                         this.printFilteredPomi();
                         break;
                     default:
                         System.out.println("Invalid option!");
                    }
                }
                catch(InputMismatchException e) {
                    console.nextLine();
                    System.out.println("Please enter a number, not a string.");
                }
                catch(Exception e) {
                    System.out.println(e.getMessage());
                }

            
            }
        }

}
//Intr-o livada cresc meri, peri si ciresi.
//Sa se afiseze toti pomii frunctiferi mai batrini
//de 3 ani.