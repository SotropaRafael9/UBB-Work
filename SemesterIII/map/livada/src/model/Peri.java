package model;

public class Peri implements Pomi{
    private int age;

    public Peri(int age)
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
        return "Acesti Peri au " + age + " ani.";
    }

}
