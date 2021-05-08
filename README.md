#  Basis Functions

Assignment 1 for the course, Foundations of Data Science, taught by Dr. Navneet Goyal in Second Semester 2020-21 at BITS Pilani.

- Niranjan Ashok Jahagirdar
- Pranay Khariwal

# Code explanation

"POLYNOMIAL"

Inputs: Size
	X,Y cordinates
	Degree 

Outputs: Curve equation with corresponding coefficient weights

-------------------------------------------------------------------------------------------------------

"SIGMOIDAL"

Inputs: Size
	X,Y cordinates

Outputs: Curve cordinates
	 MSE_error 

-------------------------------------------------------------------------------------------------------

"Gaussian"

Inputs: Size
	X,Y cordinates

Outputs: Curve cordinates
	 MSE_error 

----------------------------------------------------------------------------------------------------------
"FOURIER"

Inputs: Size
	X,Y cordinates
	Curve type       
	scaling Factor
	Shitfting factor

Outputs: Curve Cordinates
	 MSE_error

-----------------------------------------------------------------------------------------------------------
"SPLINES"

Inputs: Size
	X,Y cordinates
	Degree       
	Number of Knots
	Corresponding knot values

Outputs: Equation of each knot Interval with best fit coefficient weights for given degree of polynomial
	
------------------------------------------------------------------------------------------------------------
"WAVELETS"

Inputs: Size
	X,Y cordinates
	sigma     
	scaling Factor
	Shitfting factor

Outputs: Curve Cordinates
	 MSE_error
