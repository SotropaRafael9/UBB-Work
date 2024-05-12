import repository.MemoryRepo;
import view.View;
import controller.Controller;
public class Main {
    public static void main(String[] args) {
        MemoryRepo repo = new MemoryRepo(50);
        Controller service = new Controller(repo);
        View UI = new View(service);

        UI.run();

    }
}

//Intr-o livada cresc meri, peri si ciresi.
//Sa se afiseze toti pomii frunctiferi mai batrini
//de 3 ani.