// https://www.twitch.tv/videos/820855594



let NOMBRE_ETOILES = 10;
let MAX_MASS = 10;
let TAILLE = 10;
let FRAMERATE = 10;

let listeEtoiles = []; 
let CST_G = 6.27e-11;
let jez;
let force;



function setup() 
{
	frameRate(1);
	createCanvas(windowWidth, windowHeight);

	print("Window Width : &{windowWidth}");
	print("Window Height : &{windowHeight}");
	background(0);

	for (let i = 0; i < NOMBRE_ETOILES; i++) 
	{
		// Create a list of "etoiles" with random mass and position Vector
		listeEtoiles.push( new etoile() );
	}


	force = createVector(-10, -20);

	print(computeForces(createVector(400, 600), createVector(50, 600)));

	
}


function draw() 
{
	background(0);
	
	for (let i = 0; i < listeEtoiles.length; i++)
	{
		listeEtoiles[i].GetAccFromForce(force);
		// print("Acceleration  de l'etoile "+ i +  ' ' + listeEtoiles[i].vecAcc);

		listeEtoiles[i].update();

		// print("Position X de l'etoile "+ i +  ' ' + listeEtoiles[i].vecPos.x);
		// print("Position Y de l'etoile "+ i  + ' ' + listeEtoiles[i].vecPos.y )
		// print("Velocity  de l'etoile "+ i  + ' ' + listeEtoiles[i].vecVel + "\n --------------------");

		listeEtoiles[i].show();
	}

}


function computeForces(etoile1, etoile2)
{
	v1 = etoile1.vecPos;
	v2 = etoile2.vecPos;

	let tempVec = v1.sub(v2);
	
	let distVec = tempVec.mag();

	let result = (CST_G * etoile1.mass * etoile2.mas) / (distVec * distVec * distVec);
	result *= tempVec;
	return result ;
}

class etoile 
{
	constructor()
	{
		this.vecPos = createVector( random(100, windowWidth - 100 ), random(100, windowHeight - 100) );
		//this.vecPos = createVector( 100, 300 );
		this.mass = random(1, MAX_MASS);
		this.vecAcc = createVector(0, 0);
		this.vecVel = createVector(0, 0);

	}

	update()
	{
		this.vecVel.add(this.vecAcc);	//add the acc to get the velocity
		this.vecPos.add(this.vecVel);	//Add vel to the current pos
		
		
	}

	GetAccFromForce(force)
	{
		this.vecAcc.mult(0);			//reset acc
		let f = createVector();
		f = createVector(-10, 1).div(this.mass);
		this.vecAcc.add( f );
	}

	

	show()
	{
		fill(255);
		circle(this.vecPos.x, this.vecPos.y, TAILLE);
	}

}




	// for (let i = 0; i < listeEtoiles.length; i++)
	// {
	// 	let bufferVec = createVector(0, 0);
	// 	let summVec;
	// 	let tempCalc;

	// 	for (let j = 0; j < listeEtoiles.length; j++)
	// 	{
			
	// 		if(j != i)
	// 		{
	// 			//add the 2 vectors to get
	// 			bufferVec.add(listeEtoiles[i].vecPos);
	// 			bufferVec.add(listeEtoiles[j].vecPos);
	// 			tempCalc = CST_G * (listeEtoiles[i].mass + listeEtoiles[j].mass);
	// 			summVec +=  tempCalc / pow(bufferVec.mag(), 2) ;//* listeEtoiles[i].vecVel;
	// 		}
	// 	}

	// 	listeEtoiles[i].vecVel = summVec / listeEtoiles[i].mass;
	// 	console.log(tempCalc / pow(bufferVec.mag(), 3) );
	// 	listeEtoiles[i].update();
	// 	listeEtoiles[i].show();
		
	

	// }

