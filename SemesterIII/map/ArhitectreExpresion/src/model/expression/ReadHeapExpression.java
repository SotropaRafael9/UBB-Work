package model.expression;

import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.type.RefType;
import model.type.Type;
import model.value.RefValue;
import model.value.Value;

public class ReadHeapExpression implements IExpression{
    private final IExpression expression;

    public ReadHeapExpression(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ADTExceptions, ExpressionEvaluationExceptions {
        Value value = expression.eval(symTable, heap);
        if (!(value instanceof RefValue))
            throw new ExpressionEvaluationExceptions(String.format("%s not of RefType", value));
        RefValue refValue = (RefValue) value;
        return heap.get(refValue.getAddress());
    }

    @Override
    public IExpression deepCopy() {
        return new ReadHeapExpression(expression.deepCopy());
    }
    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws ExpressionEvaluationExceptions, ADTExceptions {
        Type type = expression.typeCheck(typeEnv);
        if (type instanceof RefType){
            RefType refType = (RefType) type;
            return refType.getInner();
        }
        else
            throw new ExpressionEvaluationExceptions("The rH argument is not a RefType!");
    }
    @Override
    public String toString() {
        return String.format("ReadHeap(%s)", expression);
    }
}
