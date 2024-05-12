package model.expression;
import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.value.Value;
import model.type.Type;

public class ValueExpression implements  IExpression{
    Value value;
    public ValueExpression(Value value) {
        this.value = value;
    }


    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ADTExceptions, ExpressionEvaluationExceptions {
        return this.value;
    }
    @Override
    public IExpression deepCopy() {
        return new ValueExpression(value.deepCopy());
    }
    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws ExpressionEvaluationExceptions, ADTExceptions {
        return value.getType();
    }
    @Override
    public String toString(){
        return this.value.toString();
    }
}
