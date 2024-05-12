package model;

public class Meri implements Pomi{
    private int age;

    public Meri(int age)
    {
        this.age = age;
    }

    @Override
    public int getAge()
    {
        return age;
    }

    @Override
    public void setAge(int age)
    {
        this.age = age;
    }
    @Override
    public String toString()
    {
        return "Acesti Meri au " + age + " ani.";
    }

}
