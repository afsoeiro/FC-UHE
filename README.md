
# FC-UHE
### My *Electrical Engineering* Graduation Project

The project in this folder was developed by me (*Andre Soeiro*) and released in 2001 as part of my Bachelor Degree in the [Electrical Engineering Department](http://www.ene.unb.br/) at [Universidade de Bras&iacute;lia](https://wwww.unb.br).

This is an old project, as it was developed *over twenty years ago*. It was compiled with the then called [**Borland C++ Builder 1.0** IDE](https://en.wikipedia.org/wiki/C%2B%2BBuilder).

Most of my class naming conventions came along with the patterns I learned from the Borland C++ Builder conventions. I believe, as I look back now, that they used the capital letter T before every class name to signal it is only a *Template* for the object being created.

From what I recall, I had the need to use several types of data structures, such as Queue and Stack. I wrote my own of those in the form of linked lists. So, I built a base Object item to be stored in the data structures. All other element classes (variables, mathematical expressions, calculation routines, etc.) derived from the base Object.

The *software* allows us to program a series of mathematical expressions and text outputs and order them in a way that you get a report of those calculations. Results from former expressions can be used as inputs to other expressions. The user determine which variables are to be input on every time the whole project is to be calculated. Once the results are ready it emits a Rich Text report.

The Rich Text component used was a commercial one, that would give me the right to use it for a trial period that was enough for what I needed in the graduation project. Back then, it was not that easy to generate Rich Text from C++.

The mathematical expression evaluation is done using the [Shunting Yard algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm). Basically, we:

 1. Take infix mathematical expressions, including unlimited parenthesis;
 2. convert them to Reverse Polish Notation (RPN, used in HP 48 calculator series, for example);
 3. Evaluate the RPN expression.

Well, this is it, the code is all here, and can be used or ported anywhere you want to. If you could tell me if you found anything useful on it, or if you're using it anywhere, I will be grateful. Feel free to reference it anywhere if you want to.

*Andre Soeiro*
 , 
> Written with [StackEdit](https://stackedit.io/).
