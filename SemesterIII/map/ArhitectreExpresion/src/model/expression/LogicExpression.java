package model.expression;

import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.value.Value;
import model.value.BoolValue;
import model.type.BoolType;
import model.type.Type;
import model.type.IntType;

import java.util.Objects;
public class LogicExpression implements  IExpression{
    IExpression expression1;
    IExpression expression2;
    String operation;

    public LogicExpression(IExpression expression1, IExpression expression2, String operation) {
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.operation = operation;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ADTExceptions, ExpressionEvaluationExceptions {
        Value value1, value2;
        value1 = this.expression1.eval(symTable, heap);
        if(value1.getType().equals(new BoolType())){
            value2 = this.expression2.eval(symTable, heap);
            if(value2.getType().equals(new BoolType())){
                BoolValue bool1 = (BoolValue) value1;
                BoolValue bool2 = (BoolValue) value2;
                boolean b1, b2;
                b1 = bool1.getValue();
                b2 = bool2.getValue();
                if(Objects.equals(this.operation, "and")){
                    return new BoolValue(b1 && b2);
                } else if(Objects.equals(this.operation,"or")){
                    return new BoolValue(b1 || b2);
                }
            } else
                throw new ExpressionEvaluationExceptions("Second operand is not of boolean type!");
        } else
            throw new ExpressionEvaluationExceptions("The first operand is not of boolean type!");
        return null;
    }
    @Override
    public IExpression deepCopy() {
        return new LogicExpression(expression1.deepCopy(), expression2.deepCopy(), operation);
    }
    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws ExpressionEvaluationExceptions, ADTExceptions {
        Type type1, type2;
        type1 = expression1.typeCheck(typeEnv);
        type2 = expression2.typeCheck(typeEnv);
        if(type1.equals(new BoolType())){
            if(type2.equals(new BoolType())){
                return new IntType();
            }
            throw new ExpressionEvaluationExceptions("Second operand is not a boolean!");
        }
        throw new ExpressionEvaluationExceptions("First operand is not a boolean!");
    }
    @Override
    public String toString(){
        return expression1.toString() + " " + operation + " " + expression2.toString();
    }
}
