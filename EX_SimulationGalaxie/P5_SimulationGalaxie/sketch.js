// https://www.twitch.tv/videos/820855594


//Parameters
let NOMBRE_ETOILES = 20;
let MASS = 0.01;
let TAILLE = 5;
let FRAMERATE = 15;


//Global Variables
let starsList = []; 
let CST_G = 6.674e-11;
let summForces;

function setup() 
{
	frameRate(FRAMERATE);
	createCanvas(windowWidth, windowHeight);
	//background(0);

	//Create random stars
	for (let i = 0; i < NOMBRE_ETOILES; i++) 
	{
		// Create a list of "stars" with random mass and position Vector
		starsList.push( new etoile(createVector( random(500, windowWidth -500), random(0, windowHeight - 50), random(0.0001, MASS) )));
	}

	//create a black hole
	starsList.push(new etoile(createVector(windowWidth / 2, windowHeight / 2), 1000000));
	summForces = createVector(0, 0);
}


function draw() 
{
	background(0);
	for (let i = 0; i < starsList.length; i++)
	{
		//Summ up all the forces for each stars
		for (let j = 0; j < starsList.length; j++)
		{
			if(j != i) //does not compute its own force
			{
				summForces.add(computeForce(starsList[j], starsList[i]));
			}
		}
		
		starsList[i].GetAccFromForce(summForces);
		summForces.mult(0); //reset the summ
		starsList[i].update();
		starsList[i].show();
	}
}

function computeForce(etoile1, etoile2)
{
	v1 = etoile1.vecPos.copy();
	v2 = etoile2.vecPos.copy();

	let distVec = etoile1.vecPos.dist(etoile2.vecPos);
	distVec.x = constrain(distVec.x, 100, 500);
	distVec.y = constrain(distVec.y, 100, 500);

	let force = v1.sub(v2);
	force.setMag( (CST_G * etoile1.mass * etoile2.mass) / (distVec * distVec * distVec) );
	return force;
}

class etoile 
{
	constructor(_vecPos, _mass)
	{
		this.vecPos = _vecPos;
		this.mass = _mass;
		this.vecAcc = createVector(0, 0);
		this.vecVel = createVector(0, 0);
	}

	update()
	{
		this.vecVel.add(this.vecAcc);	//add the acc to get the velocity
		this.vecPos.add(this.vecVel);	//Add vel to the current pos
		this.vecAcc.mult(0);			//reset acc
	}

	GetAccFromForce(force)
	{
		let f = createVector(0, 0);
		f = force.div(this.mass);
		this.vecAcc.add( f );
	}

	show()
	{
		fill(255);
		circle(this.vecPos.x, this.vecPos.y, TAILLE);
	}

}

