Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Recursion Tutorial!
Prerequesites: None

Recursion is type of loop, similar to a 'for' loop, or a 'while' loop.
All types of loops have a beginning condition, a repeat condition, and an 
end condition. Recursion is the calling of a function, inside of itself, 
repeatedly, until the end condition is met, and then the function finally ends.

Here is a simple example of recursion:

void loop(int i)
{
	cout << i << endl;
	i++;
	
	if(i < 10)
		loop(i);
}

int main()
{
	loop(5);
}
