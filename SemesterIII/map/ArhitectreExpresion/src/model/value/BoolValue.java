package model.value;

import model.type.BoolType;
import model.type.Type;

public class BoolValue implements Value{
    private boolean value;

    public void BoolType(boolean val){
        this.value = val;
    }

    public BoolValue(boolean b) {this.value = b;
    }

    public boolean equals(Type another){
        return another instanceof BoolType;
    }



    public boolean getValue(){
        return this.value;
    }

    @Override
    public Type getType(){
        return new BoolType();
    }
    @Override
    public Value deepCopy() {
        return new BoolValue(value);
    }
    @Override
    public String toString(){
        return this.value ? "true" : "false";
    }
}
