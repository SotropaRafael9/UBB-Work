package repository;
import model.Pomi;
public class MemoryRepo implements IRepository {
    private int size;
    private int elems;
    private Pomi[] data;

    public MemoryRepo(int size)
    {
        this.data = new Pomi[size];
        this.elems = 0;
        this.size = size;
    }

    @Override
    public void addPomi(Pomi pomi)
    {
        this.data[this.elems++] = pomi;
    }

    @Override
    public void removePomi(int index) throws ArrayIndexOutOfBoundsException
    {
        if(index < 0 || index >= this.elems)
            throw new ArrayIndexOutOfBoundsException("the given element is not in the repo");
        this.data[index] = this.data[this.elems-1];
        this.data[this.elems-1] = null;
        this.elems--;
    }

    @Override
    public int getSize()
    {
        return this.elems;
    }

    @Override
    public Pomi[] getAll(){
        return this.data;
    }

}
