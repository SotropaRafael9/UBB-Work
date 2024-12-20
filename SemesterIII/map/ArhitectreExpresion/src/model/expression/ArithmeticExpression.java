package model.expression;

import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.value.Value;
import model.type.IntType;
import model.type.Type;
import model.value.IntValue;


public class ArithmeticExpression implements IExpression{
    IExpression expression1;
    IExpression expression2;
    char operation;

    public ArithmeticExpression(char operation, IExpression expression1, IExpression expression2) {
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.operation = operation;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ADTExceptions, ExpressionEvaluationExceptions {
        Value value1, value2;
        value1 = this.expression1.eval(symTable,heap);
        if(value1.getType().equals(new IntType())){
            value2 = this.expression2.eval(symTable,heap);
            if(value2.getType().equals(new IntType())){
                IntValue int1 = (IntValue) value1;
                IntValue int2 = (IntValue) value2;
                int n1, n2;
                n1 = int1.getValue();
                n2 = int2.getValue();
                if(this.operation == '+'){
                    return new IntValue(n1+n2);
                }
                else if(this.operation == '-'){
                    return new IntValue(n1-n2);
                }
                else if(this.operation == '*'){
                    return new IntValue(n1*n2);
                }
                else if(this.operation == '/'){
                    if(n2 != 0)
                        return new IntValue(n1/n2);
                    else
                        throw new ExpressionEvaluationExceptions("Division by 0!");
                }
            } else {
                throw new ExpressionEvaluationExceptions("Second operand is not an integer!");
            }
        }
        else {
            throw new ExpressionEvaluationExceptions("First operand is not an integer!");
        }
        return null;
    }
    @Override
    public IExpression deepCopy() {
        return new ArithmeticExpression(operation, expression1.deepCopy(), expression2.deepCopy());
    }
    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws ExpressionEvaluationExceptions, ADTExceptions {
        Type type1, type2;
        type1 = expression1.typeCheck(typeEnv);
        type2 = expression2.typeCheck(typeEnv);
        if(type1.equals(new IntType())){
            if(type2.equals(new IntType())){
                return new IntType();
            }
            throw new ExpressionEvaluationExceptions("Second operand is not an integer!");
        }
        throw new ExpressionEvaluationExceptions("First operand is not an integer!");
    }
    @Override
    public String toString(){
        return expression1.toString() + " " + operation + " " + expression2.toString();
    }
}
