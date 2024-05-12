package model.statements;

import exceptions.InterpreterException;
import expressions.Expression;
import expressions.RelationalExpression;
import expressions.VariableExpression;
import model.programState.ProgramState;
import model.adts.IDictionary;
import model.adts.IStack;
import model.programState.ProgramState;
import model.statements.AssignStatement;
import model.statements.CompoundStatement;
import model.statements.IStatement;
import model.statements.WhileStatement;
import model.types.IntType;
import model.types.Type;

public class ForStatement implements IStatement {
    private String var;
    private Expression expr1;
    private Expression expr2;
    private Expression expr3;
    private IStatement st;

    public ForStatement(String _var, Expression _expr1, Expression _expr2, Expression _expr3, IStatement _st){
        var = _var;
        expr1 = _expr1;
        expr2 = _expr2;
        expr3 = _expr3;
        st = _st;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        IStack<IStatement> stack = state.getExecutionStack();

        IStatement newSt = new CompoundStatement(new AssignStatement(var, (model.expressions.Expression) expr1), new WhileStatement(
                new RelationalExpression("<", new VariableExpression(var), expr2), new CompoundStatement(
                st, new AssignStatement(var, expr3)
        )
        ));
        stack.push(newSt);
        return null;
    }

    @Override
    public IStatement deepCopy() {
        return new ForStatement(var, expr1.deepCopy(), expr2.deepCopy(), expr3.deepCopy(), st.deepCopy());
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws InterpreterException {
        Type typexpr1 = expr1.typeCheck(typeEnv);
        Type typexpr2 = expr1.typeCheck(typeEnv);
        Type typexpr3 = expr1.typeCheck(typeEnv);

        if (typexpr1.equals(new IntType()))
            if (typexpr2.equals(new IntType()))
                if (typexpr3.equals(new IntType()))
                    return typeEnv;
                else
                    throw new InterpreterException("Expression 3 is not of type Int.");
            else
                throw new InterpreterException("Expression 2 is not of type Int.");
        else
            throw new InterpreterException("Expression 1 is not of type Int.");
    }

    @Override
    public String toString() {
        return String.format("for(%s=%s; %s<%s; %s=%s){%s}", var, expr1.toString(), var, expr2.toString(), var, expr3.toString(), st.toString());
    }
}
