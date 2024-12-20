package model.value;

import model.type.StringType;
import model.type.IntType;
import model.type.Type;
public class StringValue implements Value{
    private final String val;


    public StringValue(String value) {
        this.val = value;
    }

    public String getValue(){
        return this.val;
    }

    @Override
    public Type getType() {
        return new StringType();
    }
    public Value deepCopy() {
        return new StringValue(val);
    }


    @Override
    public String toString() {
        return "\"" + this.val + "\"";
    }
}
