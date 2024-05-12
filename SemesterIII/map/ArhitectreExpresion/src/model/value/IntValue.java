package model.value;

import model.type.IntType;
import model.type.Type;
public class IntValue implements Value{
    private final int value;

    public IntValue(int v){
        value = v;
    }

    public int getValue(){
        return this.value;
    }

    @Override
    public Type getType()
    {
        return new IntType();
    }
    @Override
    public Value deepCopy() {
        return new IntValue(value);
    }

    @Override
    public String toString(){
        return String.format("%d", this.value);
    }
}
