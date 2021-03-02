# Contributing
Trhough the *things* there are some //TODO to do. (Or not)
If something new wants to be added the next constrains must be taken into consideration.

**Coding**

	* All functions are camelCased and self documented with an example of use.
	* All classes/structs are PropertyCased and self documented with an example of use.
	* All functions/classes should be under P23 namespace (PetaCreepers23Utils -> P23U too long -> P23)

**File Naming**

	* If the file contains non templated code, it should be .hpp extension.
	* If the file contains only templated code, it should be .h extension.
	* No .cpp files allowed, I restrict this for easy include and compile.
	* If the file contains utility about a thing, it should be name utilityThing.*
	* If the file contains only one class for a task it should be named classTask.*
	* The testing file inside test should be named [Thing|Task]-test.cpp

**Testing**

	* All functionality and templates should be tested.
	* The testing should be on the tests folder, using google test as the testing suite.
	* Unit testing all functionality is recommended. At least the example case of use should be done.
	* See the naming for the test files in the naming section.

**Continuous Integration**

	* CI Workflows are setup using GitHub Actions in .github/workflows.
	* For every new feature added, updated on the build system should be done to keep CI flowing.
