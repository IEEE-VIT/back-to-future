// Infix to Postfix Conversion using Stack in JavaScript

function precedence (c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

function isOperand (c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
		return 1;
	}
	return 0;
}

function infixToPostfix(s){
    let st = []; 
    let postFix = "";

    for (let i = 0; i < s.length; i++) {
        if (isOperand(s[i])) {
            postFix += s[i];
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while (st[st.length - 1] != '(') {
                postFix += st[st.length - 1];
                st.pop();
            }
            st.pop();
        }
        else {
            while (st.length != 0 && precedence(s[i]) <= precedence(st[st.length - 1])) {
                postFix += st[st.length - 1];
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (st.length != 0) {
        postFix += st[st.length - 1];
        st.pop();
    }
    return postFix;
}



console.log(infixToPostfix("a+b*(c^d-e)^(f+g*h)-i"));

// Output:
// abcd^e-fgh*+^*+i-