package model;

public class Ciresi implements Pomi{
    private int age;

    public Ciresi(int age)
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
        return "Acesti Ciresi au " + age + " ani.";
    }

}
