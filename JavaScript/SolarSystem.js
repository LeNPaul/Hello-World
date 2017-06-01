function Planet(mass, colour, px, py, vx, vy){
	this.mass = mass;
	this.colour = colour;
	this.px = px;
	this.py = py;
	this.vx = vx;
	this.vy = vy;
}

mercury = new Planet(100,orange,0,0,0,0)

console.log(mercury.mass);