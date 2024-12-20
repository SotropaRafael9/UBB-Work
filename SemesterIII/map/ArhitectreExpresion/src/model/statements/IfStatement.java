package model.statements;

import exceptions.ADTExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.programState.ProgramState;
import model.adt.stack.MyIStack;
import model.adt.dictionary.MyIDictionary;
import model.expression.IExpression;
import model.type.BoolType;
import model.type.Type;
import model.value.Value;
import model.value.BoolValue;
public class IfStatement implements IStatement{
    IExpression expression;
    IStatement thenStatement;
    IStatement elseStatement;

    public IfStatement(IExpression expression, IStatement thenStatement, IStatement elseStatement) {
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }


    @Override
    public ProgramState execute(ProgramState state) throws ADTExceptions, ExpressionEvaluationExceptions, StatementExecutionExceptions {
        Value result = this.expression.eval(state.getSymTable(), state.getHeap());
        if (result.getType().equals(new BoolType())){
            BoolValue condition = (BoolValue) result;
            IStatement statement;
            if(condition.getValue())
                statement = thenStatement;
            else
                statement = elseStatement;

            MyIStack<IStatement> stack = state.getExeStack();
            stack.push(statement);
            state.setExeStack(stack);
            return null;
        } else{
            throw new StatementExecutionExceptions("The expression cannot be evaluated as true or false!");
        }
    }
    @Override
    public IStatement deepCopy() {
        return new IfStatement(expression.deepCopy(), thenStatement.deepCopy(), elseStatement.deepCopy());
    }
    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        Type typeExp = expression.typeCheck(typeEnv);
        if (typeExp.equals(new BoolType())){
            thenStatement.typeCheck(typeEnv.deepCopy());
            elseStatement.typeCheck(typeEnv.deepCopy());
            return typeEnv;
        } else
            throw new StatementExecutionExceptions("The condition of if was not of type bool!");
    }
    @Override
    public String toString() {
        return String.format("if(%s){%s}else{%s}", expression.toString(), thenStatement.toString(), elseStatement.toString());
    }
}
