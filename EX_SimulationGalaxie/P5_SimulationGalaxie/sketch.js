// https://www.twitch.tv/videos/820855594


let listeEtoiles = []; 
let NOMBRE_ETOILES = 10;
let MAX_MASS = 100000;
let CST_G = 9.89;


function setup() 
{
	createCanvas(windowWidth, windowHeight);
	print("Window Width : &{windowWidth}");
	print("Window Height : &{windowHeight}");
	background(0);

	for (let i = 0; i < NOMBRE_ETOILES; i++) 
	{
		// Create a list of "etoiles" with random mass and position Vector
		listeEtoiles.push( new etoile(createVector( random(100, windowWidth - 200), random(100, windowHeight - 200) ) , random(0, MAX_MASS) ) );
	}

}


function draw() 
{
	background(0);

	for (let i = 0; i < listeEtoiles.length; i++)
	{
		let bufferVec = createVector(0, 0);
		let summVec;
		let tempCalc;

		for (let j = 0; j < listeEtoiles.length; j++)
		{
			
			if(j != i)
			{
				//add the 2 vectors to get
				bufferVec.add(listeEtoiles[i].vecPos);
				bufferVec.add(listeEtoiles[j].vecPos);
				tempCalc = CST_G * (listeEtoiles[i].mass + listeEtoiles[j].mass);
				summVec +=  tempCalc / pow(bufferVec.mag(), 2) ;//* listeEtoiles[i].vecVel;
			}
		}

		listeEtoiles[i].vecVel = summVec / listeEtoiles[i].mass;
		console.log(tempCalc / pow(bufferVec.mag(), 3) );
		listeEtoiles[i].update();
		listeEtoiles[i].show();
		
	}


}


class etoile 
{
	constructor(vecPos, mass)
	{
		this.vecPos = vecPos;
		this.mass = mass;
		this.vecVel;
	}

	update()
	{
		this.vecPos.add(this.vecVel); 
	}

	show()
	{
		fill(255);
		circle(this.vecPos.x, this.vecPos.x, 20);
	}


	

}


