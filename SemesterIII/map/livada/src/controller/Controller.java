package controller;
import model.*;
import repository.*;
public class Controller {

    private IRepository repo;

    public Controller(IRepository r)
    {
        this.repo = r;
    }
    public void addPomi(String type, int age) throws Exception{
        if(age <= 0)
            throw new Exception("Age cannot be 0");
        switch (type) {
            case "ciresi": {
                Ciresi pom = new Ciresi(age);
                this.repo.addPomi(pom);
                break;
            }
            case "meri": {
                Meri pom = new Meri(age);
                this.repo.addPomi(pom);
                break;
            }

            case "peri": {
                Peri pom = new Peri(age);
                this.repo.addPomi(pom);
                break;
            }
            default:
                throw new Exception("Invalid Pom type");
        }
    }
    public void removePomi(int index) throws ArrayIndexOutOfBoundsException
    {
        this.repo.removePomi(index);
    }
    public Pomi[] getPomi() throws Exception {
        if (this.repo.getSize() == 0)
            throw new Exception("");
        return this.repo.getAll();
    }

    public Pomi[] getPomiFilteredByAge(int age) throws Exception {

            if (this.repo.getSize() == 0)
                throw new Exception("Nu exista in pomi in repository");
            Pomi[] pomi = this.repo.getAll();
            Pomi[] filterPomi = new Pomi[this.repo.getSize()];
            int addedElems = 0;

            for(int i = 0 ;i< pomi.length;i++) {
                if (pomi[i] != null && pomi[i].getAge() >= 3)
                    filterPomi[addedElems++] = pomi[i];
            }
            if (addedElems == 0)
                throw new Exception("Nu sunt pomi care au varsta mai mare ca "+ age + ".");
            return filterPomi;
    }

}
