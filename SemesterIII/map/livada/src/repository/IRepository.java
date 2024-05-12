package repository;
import model.Pomi;

public interface IRepository {
    void addPomi(Pomi pomi);
    void removePomi(int index) throws ArrayIndexOutOfBoundsException;
    Pomi[] getAll();
    int getSize();


}
