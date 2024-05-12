package model.statements;

import exceptions.ADTExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.programState.ProgramState;
import model.type.Type;
import model.adt.dictionary.MyIDictionary;

public class NopStatement implements IStatement{
    @Override
    public ProgramState execute(ProgramState state) throws ADTExceptions, ExpressionEvaluationExceptions, StatementExecutionExceptions {
        return null;
    }
    @Override
    public IStatement deepCopy() {
        return new NopStatement();
    }
    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        return typeEnv;
    }
    @Override
    public String toString() {
        return "NopStatement";
    }
}
