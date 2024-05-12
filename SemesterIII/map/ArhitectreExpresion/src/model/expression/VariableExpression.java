package model.expression;
import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.value.Value;
import model.type.Type;

public class VariableExpression implements  IExpression{
    String key;
    public VariableExpression(String key) {
        this.key = key;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ADTExceptions, ExpressionEvaluationExceptions {
        return symTable.lookUp(key);
    }
    @Override
    public IExpression deepCopy() {
        return new VariableExpression(key);
    }
    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws ExpressionEvaluationExceptions, ADTExceptions {
        return typeEnv.lookUp(key);
    }
    @Override
    public String toString(){
        return this.key;
    }
}
