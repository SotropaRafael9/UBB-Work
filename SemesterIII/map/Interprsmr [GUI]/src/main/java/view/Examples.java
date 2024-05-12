package view;

import model.expressions.*;
import model.statements.*;
import model.types.BoolType;
import model.types.IntType;
import model.types.ReferenceType;
import model.types.StringType;
import model.values.BoolValue;
import model.values.IntValue;
import model.values.StringValue;

import java.util.ArrayList;
import java.util.List;

public class Examples {

    public static List<IStatement> initExamples()
    {
        List<IStatement> list = new ArrayList<>();
        // make me a new statement that is a compound statement
        // for(v = expr1; v < expr2; v = expr3) stmt
        IStatement test = new CompoundStatement(new DeclarationStatement(new IntType(), "v"), new CompoundStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))), new PrintStatement(new VariableExpression("v"))));


        IStatement example1 = new CompoundStatement(new DeclarationStatement( new IntType(),"v"), // bad example
                new CompoundStatement(new AssignStatement("v", new ValueExpression(new StringValue("312"))), //IntValue(2)
                        new PrintStatement(new VariableExpression("v"))));
        IStatement example2 = new CompoundStatement(
                new DeclarationStatement(new IntType(), "a"),
                new CompoundStatement(new DeclarationStatement(new IntType(), "b"),
                        new CompoundStatement(new AssignStatement("a", new ArithmeticExpression("+",
                                new ValueExpression(new IntValue(2)),
                                new ArithmeticExpression("*", new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompoundStatement(new AssignStatement("b",
                                        new ArithmeticExpression("+", new VariableExpression("a"),
                                                new ArithmeticExpression("+", new VariableExpression("a"), new ValueExpression(new IntValue(1))))),
                                        new PrintStatement(new VariableExpression("b"))))));
        IStatement example3 = new CompoundStatement(
                new DeclarationStatement(new BoolType(), "a"), new CompoundStatement(
                new DeclarationStatement(new IntType(), "v"), new CompoundStatement(
                new AssignStatement("a", new ValueExpression(new BoolValue(true))), new CompoundStatement(
                new IfStatement(new VariableExpression("a"), new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                new PrintStatement(new VariableExpression("v"))))));
        IStatement example4 = new CompoundStatement(new DeclarationStatement(new StringType(), "varf"),
                new CompoundStatement(new AssignStatement("varf", new ValueExpression(new StringValue("D:\\Faculta\\MAP\\MAP2022-2023\\Interpretersmr\\src\\View\\test.in"))),
                        new CompoundStatement(new OpenReadFile(new VariableExpression("varf")), new CompoundStatement(
                                new DeclarationStatement(new IntType(), "varc"), new CompoundStatement(
                                new ReadFile(new VariableExpression("varf"), "varc"),
                                new CompoundStatement(new PrintStatement(new VariableExpression("varc")), new CompoundStatement(
                                        new ReadFile(new VariableExpression("varf"), "varc"), new CompoundStatement(
                                        new PrintStatement(new VariableExpression("varc")), new CloseReadFile(new VariableExpression("varf"))))))))));
        IStatement example5 = new CompoundStatement(new DeclarationStatement(new ReferenceType(new IntType()),"v"),
                new CompoundStatement(new NewStatement("v", new ValueExpression(new IntValue(20))), new CompoundStatement(
                        new DeclarationStatement(new ReferenceType(new ReferenceType(new IntType())), "a"), new CompoundStatement(
                        new NewStatement("a", new VariableExpression("v")), new CompoundStatement(new PrintStatement(new ReadHeap(new VariableExpression("v"))),
                        new PrintStatement(new ArithmeticExpression("+", new ReadHeap(new ReadHeap(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        IStatement example6 = new CompoundStatement(new DeclarationStatement(new ReferenceType(new IntType()), "v"), new CompoundStatement(
                new NewStatement("v", new ValueExpression(new IntValue(20))), new CompoundStatement(
                new PrintStatement(new ReadHeap(new VariableExpression("v"))), new CompoundStatement(new WriteHeap("v", new ValueExpression(new IntValue(30))),
                new PrintStatement(new ArithmeticExpression("+", new ReadHeap(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        IStatement example7 = new CompoundStatement(new DeclarationStatement(new IntType(), "v"), new CompoundStatement(
                new AssignStatement("v", new ValueExpression(new IntValue(4))), new CompoundStatement(
                new WhileStatement(new RelationalExpression(">", new VariableExpression("v"), new ValueExpression(new IntValue(0))),
                        new CompoundStatement(new PrintStatement(new VariableExpression("v")),
                                new AssignStatement("v",new ArithmeticExpression("-", new VariableExpression("v"), new ValueExpression(new IntValue(1)))))), new PrintStatement(new VariableExpression("v")))));
        IStatement example8 = new CompoundStatement(new DeclarationStatement(new ReferenceType(new IntType()), "v"), new CompoundStatement(
                new NewStatement("v", new ValueExpression(new IntValue(20))), new CompoundStatement(
                new DeclarationStatement(new ReferenceType(new ReferenceType(new IntType())), "a"), new CompoundStatement(
                new NewStatement("a", new VariableExpression("v")), new CompoundStatement(
                new NewStatement("v", new ValueExpression(new IntValue(30))), new PrintStatement(new ReadHeap(new ReadHeap(new VariableExpression("a")))))))));
        IStatement example9 = new CompoundStatement(new DeclarationStatement(new IntType(), "v"), new CompoundStatement(
                new DeclarationStatement(new ReferenceType(new IntType()),"a"), new CompoundStatement(
                new AssignStatement("v", new ValueExpression(new IntValue(10))), new CompoundStatement(
                new NewStatement("a", new ValueExpression(new IntValue(22))), new CompoundStatement(
                new ForkStatement(new CompoundStatement(new WriteHeap("a", new ValueExpression(new IntValue(30))), new CompoundStatement(
                        new AssignStatement("v", new ValueExpression(new IntValue(32))), new CompoundStatement(
                        new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeap(new VariableExpression("a"))))))), new CompoundStatement(
                new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeap(new VariableExpression("a")))))))));
        IStatement example10 = new CompoundStatement(new DeclarationStatement(new IntType(),"a"), new CompoundStatement( new DeclarationStatement(new IntType(), "b"),
                new CompoundStatement(new DeclarationStatement(new IntType(), "c"), new CompoundStatement(new AssignStatement("a", new ValueExpression(new IntValue(1))),
                        new CompoundStatement(new AssignStatement("b", new ValueExpression(new IntValue(2))), new CompoundStatement(new AssignStatement("c", new ValueExpression(new IntValue(5))),
                                new CompoundStatement(new SwitchStatement(new ArithmeticExpression("*", new VariableExpression("a"), new ValueExpression(new IntValue(10))),
                                        new ArithmeticExpression("*", new VariableExpression("b"), new VariableExpression("c")),
                                        new CompoundStatement(new PrintStatement(new VariableExpression("a")), new PrintStatement(new VariableExpression("b"))),
                                        new ValueExpression(new IntValue(10)), new CompoundStatement(new PrintStatement(new ValueExpression(new IntValue(100))),
                                        new PrintStatement(new ValueExpression(new IntValue(200)))), new PrintStatement(new ValueExpression(new IntValue(300)))),
                                        new PrintStatement(new ValueExpression(new IntValue(300))))))))));
        list.add(example1);
        list.add(example2);
        list.add(example3);
        list.add(example4);
        list.add(example5);
        list.add(example6);
        list.add(example7);
        list.add(example8);
        list.add(example9);
        list.add(example10);
        list.add(test);
        return list;
    }


    public static String getProg1() {
        return "int v;\nv = 2;\nPrint(v);\n";
    }

    public static String getProg3() {
        return "bool a;\nv = 2;\nPrint(v);\n";
    }

    public static String getProg2() {
        return "int a;\nint v;\na = true;\nIf a Then v = 2 Else v = 3;\nPrint(v);\n";
    }

    public static String getProg4() {
        return "string varf;\nvarf = \"test.in\";\nopenRFile(varf);\nint varc;\nreadFile(varf,varc);\nprint(varc);\nreadFile(varf,varc);\nprint(varc);\ncloseRFile(varf);\n";
    }

    public static String getProg5() {
        return "Ref int v;\nnew(v,20);\nRef Ref int a;\nnew(a,v);\nprint(readHeap(v));\nprint(readHeap(readHeap(a)) + 5);\n";
    }

    public static String getProg7() {
        return "int v;\nv = 4;\n(while (v > 0) print(v); v = v - 1);\nprint(v)";
    }

    public static String getProg6() {
        return "Ref int v;\nnew(v,20);\nprint(readHeap(v));\nwriteHeap(v,30);\nprint(readHeap(v) + 5);\n";
    }

    public static String getProg8() {
        return "Ref int v;\nnew(v,20);\nRef Ref int a;\nnew(a,v);\nnew(v,30);\nprint(readHeap(readHeap(a)));\n";
    }

    public static String getProg9(){
        return "int v;\nRef int a;\nv = 10;\nnew(a,22);\nfork(\n\twriteHeap(a,30);\n\tv = 32;\n\tprint(v);\n\tprint(readHeap(a)));\nprint(v);\nprint(readHeap(a));\n";
    }

    public static String getProg10(){
        return "int v;\nRef int a;\nv = 10;\nnew(a,22);\nfork(\n\twriteHeap(a,30);\n\tv = 32;\n\tprint(v);\n\tprint(readHeap(a)));\nprint(v);\nprint(readHeap(a));\n";
    }

    public static List<String> getExampleStringList()
    {
        List<String> list = new ArrayList<>();
        list.add(getProg1());
        list.add(getProg2());
        list.add(getProg3());
        list.add(getProg4());
        list.add(getProg5());
        list.add(getProg6());
        list.add(getProg7());
        list.add(getProg8());
        list.add(getProg9());
        list.add(getProg10());

        return list;
    }

}
