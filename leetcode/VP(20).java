class Solution {
    public boolean isValid(String s) {
        if(s.length() <= 1) {
            return false;
        }
        
        Stack<Character> st = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if(st.empty()) {
                    return false;
                }
                
                char temp = st.peek();
                
                if((temp != '('  && c == ')') ||
                  temp != '{'  && c == '}' ||
                  temp != '['  && c == ']') {
                    return false;                    
                } else {
                    st.pop();
                }
            }
        }
        
        return st.empty();
    }
}