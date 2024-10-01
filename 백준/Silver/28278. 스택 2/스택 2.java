import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Stack{

    private int top;
    private int stackArry[];

    public Stack(int size){
        this.top = -1;
        this.stackArry = new int[size];
    }
    void push(int x){
        this.stackArry[++this.top] = x;
    }
    int pop(){
        if(top == -1) return -1;
        return stackArry[top--];
    }
    int size(){
        if(top == -1) return 0;
        return top + 1;
    }
    int empty(){
        if(top == -1) return 1;
        return 0;
    }
    int getTop(){
        if(top == -1) return -1;
        return stackArry[top];
    }
}

public class Main {
    // 예외가 발생할 수 있음을 명시하는 것임
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Stack stack = new Stack(n);

        for(int i = 0; i < n; i++){
            String line = br.readLine();
            String[] parts = line.split(" ");

            switch (parts[0]) {
                case "1": ;
                    stack.push(Integer.parseInt(parts[1]));
                    break;
                case "2":
                    System.out.println(stack.pop());
                    break;
                case "3":
                    System.out.println(stack.size());
                    break;
                case "4":
                    System.out.println(stack.empty());
                    break;
                case "5":
                    System.out.println(stack.getTop());
                    break;
            }
        }
    }
}