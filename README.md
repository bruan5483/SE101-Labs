# SE 101 Labs
This repo contains the submission for the individual and group requirements of SE101 labs. The repository includes code and documentation related to triangle classification, bug fixes, and new feature development.

## Individual Requirements
### Lab 1: Introduction to Git
Objective: Set up the project repository for lab work and import initial source code.

Steps Completed:

- Created a new Git project repository named SE101-Labs with "Internal" visibility.
- Imported the source code for the triangle program from the provided repository.

### Lab 2: Basics of Testing
Objective: Understand testing by identifying requirements, fixing bugs, and adding test cases.

Steps Completed:

- Created requirements.txt to identify key requirements for the triangle classification program.
- Fixed bugs in triangle.c:
- Ensured that the correct number of arguments is provided to the program.
- Allowed for floating point number arguments to be provided
- Ensured that the correct type of arguments (integer or float) are provided to the program.
- Ensured that rounding error was minimized.
- Added new test cases in testCaseInputs.txt to ensure that all requirements are met by the program.
- Committed and pushed all changes to the SE101-Labs repository.

## Group Requirements
### Lab 3: Adding Features with Git
Objective: Add new features (triangle type classification, line handling) using Git branching and merging.

Steps Completed:

- Created a repository with "Internal" visibility.
- Imported files (triangle.c, driver.py, requirements.txt, testCaseInputs.txt) from Lab 2.

Feature Branch 1: Line and Point Handling
- Created a branch to handle cases where the input points form a line (output the slope) or a point.
- Updated requirements.txt with requirements for handling lines and points.
- Added test cases to testCaseInputs.txt for these cases.
- Implemented the necessary code in triangle.c.

Feature Branch 2: Triangle Type Classification
- Created a branch to classify the triangle as equilateral, isosceles, or scalene.
- Updated requirements.txt to include the requirements for triangle type classification.
- Added test cases to testCaseInputs.txt for the triangle type classification feature.
Implemented the classification logic in triangle.c.

Merging
- Merged both feature branches back to the main branch.
- Ensured that the final version of triangle.c meets all the new requirements and passes the test cases.

## Authors and acknowledgment
- Original triangles.c code and testing code in driver.py written by PASW
- Bug fixes, additional features, requirements.txt, and test cases written by Bryant Ruan
