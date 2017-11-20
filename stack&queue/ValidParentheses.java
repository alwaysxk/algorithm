// 括号匹配
public class Solution {
    public boolean isValid(String s) {
        if(s.length()%2!=0)
        return false;
       Stack<Character> stack = new Stack<>();
	        char str[] = s.toCharArray();
	        for(int i = 0; i<s.length(); i++){
	        if(str[i]=='[' || str[i]=='(' || str[i]=='{'){
	                stack.push(str[i]);
	                continue;
	            }
	        if(str[i]==']' && !stack.isEmpty()){
	        	if((char)stack.pop()!='[')
	        		return false;
	        }
	        if(str[i]=='}' && !stack.isEmpty()){
	        	if((char)stack.pop()!='{')
	        		return false;
	        }
	        if(str[i]==')' && !stack.isEmpty()){
	        	if((char)stack.pop()!='(')
	        		return false;
	        }
	            
	        }      
	        
	        return stack.empty();
	       
    }
}