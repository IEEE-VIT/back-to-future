import 'dart:collection';
import 'dart:math';

class Infix {
    static int _checPrecedence(String ch) {
    switch (ch) {
        case "+":
        case "-":
        return 1;
        case "*":
        case "x":
        case "X":
        case "/":
        return 2;
        case "^":
        return 3;
        default:
        return -1;
    }
    }

    static String toPostfixExpression(String exp) {
    String result = "";
    Queue<String> stack = new Queue<String>();
    String c;
    RegExp regex = new RegExp("[a-zA-Z0-9.]+");

    for (var i = 0; i < exp.length; i++) {
        c = exp[i];
        if (regex.hasMatch(c))
        result += c;
        else if (c == '(')
        stack.add(c);
        else if (c == ')') {
        while (stack.isNotEmpty && stack.last != "(") {
            result += stack.removeLast();
        }

        if (stack.isEmpty)
          return "Invalid Expression"; // invalid expression
        else
            stack.removeLast();
        } else {
        while (stack.isNotEmpty &&
            _checPrecedence(c) <= _checPrecedence(stack.last)) {
            result += stack.removeLast();
        }
        stack.add(c);
        }
    }
    while (stack.isNotEmpty) {
        result += stack.removeLast();
    }
    return result;
    }

    static String toValue(String exp) {
    RegExp r = new RegExp("[0-9.]+");
    Queue<String> values = Queue<String>();
    Queue<String> ops = Queue<String>();
    List<String> tokens = exp.split("");
    for (var i = 0; i < tokens.length; i++) {
        if (tokens[i] == "") continue;

        if (r.hasMatch(tokens[i])) {
        String x = "";
        while (i < tokens.length && r.hasMatch(tokens[i])) x += tokens[i++];
        values.add(x);
        i--;
        } else if (tokens[i] == "(") {
        ops.add(tokens[i]);
        } else if (tokens[i] == ")") {
        while (ops.last != "(") {
            values.add(applyOp(
                    ops.removeLast(),
                    double.parse(values.removeLast()),
                    double.parse(values.removeLast()))
                .toString());
        }
        ops.removeLast();
        } else if (tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "%" ||
            tokens[i] == "^" ||
            tokens[i] == "/") {
        while (ops.isNotEmpty &&
            checPrecedence(ops.last) >= checPrecedence(tokens[i])) {
            values.add(applyOp(
                    ops.removeLast(),
                    double.parse(values.removeLast()),
                    double.parse(values.removeLast()))
                .toString());
        }
        ops.add(tokens[i]);
        }
    }

    while (ops.isNotEmpty) {
        values.add(applyOp(ops.removeLast(), double.parse(values.removeLast()),
                double.parse(values.removeLast()))
            .toString());
    }

    return values.removeLast();
    }

    static int checPrecedence(String ch) {
    switch (ch) {
        case "+":
        case "-":
        return 1;
        case "*":
        case "/":
        case "%":
        return 2;
        case "^":
        return 3;
        default:
        return -1;
    }
    }

    static double applyOp(String op, double b, double a) {
    switch (op) {
        case '+':
        return a + b;
        case '-':
        return a - b;
        case '*':
        return a * b;
        case '%':
        return a % b;
        case '^':
        return pow(a, b);
        case '/':
        if (b == 0) throw new Exception("Cannot divide by zero");
        return a / b;
    }
    return 0;
    }
}