# Unittesting

Further to the options http://blog.wingman-sw.com/linker-substitution-in-c-limitations-and-workarounds
this project explores additional possiblity of UNIT testing of your production code without updating production code.


	moduleone.c has 2 mehtods and it has dependency with moduletwo.
	How to unittest moduleone.c and moduletwo.c? 
	
	When unitesting first module, need fakes for moduletwo, and
	when testing moduletwo, need to call the actual function.. 
	That means I need a fake function for one tests and not for other tests...
	
	 

unittesting/calling_tests_from_anothergroup_tests.cpp --> could be used as an example when you want to call a test item from differnet test_group. Not sure where and when it is requried..
