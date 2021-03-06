# 后缀式

## 目的：

将中缀表达式（即标准形式的表达式）转换为后缀式。

例子：a+b*c+(d*e+f)*g转换成abc*+de*f+g*+

 

## 转换原则：

1. 当读到一个操作数时，立即将它放到输出中。操作符则不立即输出，放入栈中。遇到左圆括号也推入栈中。

2. 如果遇到一个右括号，那么就将栈元素弹出，将符号写出直到遇到一个对应的左括号。但是这个左括号只被弹出，并不输出。

3. 在读到操作符时，如果此时栈顶操作符优先性大于或等于此操作符，弹出栈顶操作符直到发现优先级更低的元素位置。
除了处理')'的时候，否则决不从栈中移走'('。操作符中，'+' '-'优先级最低，'(' ')'优先级最高。

4. 如果读到输入的末尾，将栈元素弹出直到该栈变成空栈，将符号写到输出中。

 

## 解如下：

首先，读入'a'，并送到输出，然后'+'被读入并压入栈中。接下来b读入并送到输出，此时状态如下：

栈: +                                   

输出：a b



接下来读入'*'，由于优先性比栈顶元素'+'大（原则3），因此被压入栈顶，接着读入'c'，并送到输出：

栈: + *                                 

输出：a b c

        

然后读入'+'，由于此时栈顶元素为'*'，优先级比'+'大，因此将'*'弹出，弹出后原来的'+'变成栈顶元素，由于'+'的优先性和当前读入的'+'优先性相等，因此也被弹出（原则3），最后将读入的'+'压入栈中。因此此时状态如下：

栈: +                                   

输出：a b c * +

     

下一个读入的符号是'('，由于具有最高优先级，因此将其放入栈中，然后读入'd':

栈: + (                                 

输出：a b c * + d

           

继续读入，此时读入'*'，除非处理')'，否则'('决不弹出（原则3），因此'*'被压入栈中，接下来读入'e',并送到输出：

栈: + ( *                               

输出：a b c * + d e

             

再往后读入的符号是'+'，将'*'弹出并输出。（原则3，与之前步骤相似），然后将'+'压入栈中，接着读入'f'并送到输出：

栈:    + ( +                            

输出：a b c * + d e * f

           

现在读入')'，因此弹出栈元素直到遇到'('（原则2）：

栈:    +                              

输出： a b c * + d e * f +

          

下面又读入一个'*'，被压入栈中，然后读入'g'并输出：

栈:    + *                                

输出： a b c * + d e * f + g

          

现在输入为空，弹出栈中所有元素：

栈:    空                                  

输出： a b c * + d e * f + g * +          


## 后缀表达式的计算

从左至右扫描表达式，遇到数字时，将数字压入堆栈，遇到运算符时，弹出栈顶的两个数，用运算符对它们做相应的计算（次顶元素 op 栈顶元素），并将结果入栈；重复上述过程直到表达式最右端，最后运算得出的值即为表达式的结果。
为了最好的表达出运算顺序，每一步运算都加括号，顺序为(>[>{;
例如后缀表达式“abc*+de*f+g*+”：

首先，a b c入栈

栈：abc

遇到运算符*， 弹出c和b，后弹出的在前，(b*c)入栈

栈：a (b*c)

遇到运算符+，弹出（b*c）a， [a+（b*c）]入栈 d e入栈

栈：[a+（b*c）] d e

遇到运算符*， 弹出e和d，（d*e）入栈， f入栈

栈：[a+（b*c）] （d*e）f

遇到运算符+， 弹出f和（d*e），[（d*e）+f]入栈， g入栈

栈：[a+（b*c）] [（d*e）+f] g

遇到运算符*， 弹出g和[（d*e）+f]， 	{[（d*e）+f]*g} 入栈

栈：[a+（b*c）] {[（d*e）+f]*g}

遇到运算符+，{[（d*e）+f]*g}和[a+（b*c）]弹出，

计算[a+（b*c）] +{[（d*e）+f]*g}
与原式a+b*c+(d*e+f)*g计算顺序一致；
