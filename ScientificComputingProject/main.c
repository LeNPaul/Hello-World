#include <stdio.h>
#include <math.h>
#include "cpgplot.h"
#include <time.h>

int main()
{

    //Timing how long this program takes to run

    clock_t tic = clock();

    //Setting initial conditions for demo
    //Everything in SI units

    int nsteps = 10000;
    int nparticles = 50000;;
    float radius = 6.0268E7;
    float mass = 5.6836E27;
    float moomass = 1E26;
    float initialposition = 1.3938E8;
    int range = 2.576E6;
    float G = 6.67E-11;

    float x[nsteps], y[nsteps], vx[nsteps], vy[nsteps], r[nsteps];
    float xpart[nparticles], ypart[nparticles], vxpart[nparticles], vypart[nparticles];
    float xmoon[nsteps], ymoon[nsteps], vxmoon[nsteps], vymoon[nsteps], rmoon[nsteps];

    //Setting up a moon

    xmoon[0] = 1.3938E8;
    ymoon[0] = 0.0;
    vxmoon[0] = 0.0;
    vymoon[0] = -3.7E4;

    //Integration parameters
    //Each timestep dt is 60 seconds or 1 minute

    float dt = 60.0;
    int i, k, j;

    printf("This program simulates planetary rings as a given number of point particles approximated to have insignificant mass in orbit around a central planetary mass. Included is also a moon with significant mass in orbit around the central planetary mass. \n");

    printf("Variable parameters in this simulation include the number of point particles, the range in which the initial positions and velocities of these particles  will be pseudo-randomly generated, the radius of the planet, the mass of the central planet, the initial position and velcity of the moon, the mass of the moon, and the number of time steps this simulation will take. \n");

    printf("To view a working demo of the program simulating the formation of planetary rings around Saturn, enter 1. To enter custom parameters, enter 2. \n");
    scanf("%i", &j);

    //Setting up custom parameters

    if(j == 2)
    {

    printf("Enter the number of days for which the program will simulate the orbits (recommended: 69 days): \n");
    scanf("%i", &nsteps);

    nsteps = nsteps*1440;

    printf("Please enter the mass of the central planetary mass in kilograms (recommended: 5.683E27 Kg, mass of Saturn): \n");
    scanf("%f", &mass);

    printf("Enter the radius of the central planetary mass in meters (recommended: 6.0268E7 m, equatorial radius of Saturn): \n");
    scanf("%f", &radius);

    printf("Enter the integer number of ring particles to be put into orbit around the central planetary mass (recommended: 100000 particles for reasonable run times over longer periods of time, 500000 particles for longer run times but more interesting results): \n");
    scanf("%i", &nparticles);

    printf("Enter the approximate distance from the center of the central body that the particles will be generated (recommended: 1.3938E8 m, distance of Saturn's moon Prometheus from Saturn's center, or 1.22187E9 m, distance of Saturn's moon Titan from Saturn's center): \n");
    scanf("%f", &initialposition);

    printf("Enter the range over which the particles will be generated (recommended: 5.151E6 m, the diameter Saturns largest moon Titan, starting place for particles if that moon suddenly exploded): \n");
    scanf("%i", &range);

    printf("Enter the mass of the moon orbiting the central mass body (recommended: 1.35E26 Kg, or something comparable to the central mass for visible effects; set this to zero for no moon): \n");
    scanf("%f", &moomass);

    float x[nsteps], y[nsteps], vx[nsteps], vy[nsteps], r[nsteps];
    float xpart[nparticles], ypart[nparticles], vxpart[nparticles], vypart[nparticles];
    float xmoon[nsteps], ymoon[nsteps], vxmoon[nsteps], vymoon[nsteps], rmoon[nsteps];

    printf("Enter the distance of the moon from the center of the central body (recommended: 1.3938E8 m, distance of Saturn's moon Prometheus from Saturn): \n");
    scanf("%f", &xmoon[0]);

    printf("Enter the tangential  velocity of the moon (recommended: -3.7E4, negative for a clockwise orbit when viewed from above): \n");
    scanf("%f", &vymoon[0]);

    ymoon[0] = 0.0;
    vxmoon[0] = 0.0;

    }

    if(j ==1)
    {

        //Setting initial conditions for each point particle
        //Each particle is given a random position and velocity around the central planet

        printf("This demo simulates the evolution of ");

        for(i=0;i<nparticles;i++)
        {
            xpart[i] = initialposition - rand() % range;
        }

        for(i=0;i<nparticles;i++)
        {
            ypart[i] = initialposition - rand() % range;
        }

        for(i=0;i<nparticles;i++)
        {
            vxpart[i] = 35500 - rand() % 71000;
        }

        for(i=0;i<nparticles;i++)
        {
            vypart[i] = 35500 - rand() % 71000;
        }

        //Leapfrog integration for moon's orbit

        for(i = 0; i < nsteps; i++)
        {

            rmoon[i] = sqrt(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]);
            vxmoon[i+1] = vxmoon[i] - 0.5 * dt * (xmoon[i]/rmoon[i]) * ((G*mass)/(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]));
            xmoon[i+1] = xmoon[i] + dt * vxmoon[i+1];

            rmoon[i] = sqrt(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]);
            vymoon[i+1] = vymoon[i] - 0.5 * dt * (ymoon[i]/rmoon[i]) * ((G*mass)/(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]));
            ymoon[i+1] = ymoon[i] + dt * vymoon[i+1];

        }

        //Leapfrog integration for each particle

        for(k = 0; k < nparticles; k++)
        {
            x[0] = xpart[k];
            y[0] = ypart[k];
            vx[0] = vxpart[k];
            vy[0] = vypart[k];

            for(i = 0; i < nsteps; i++)
            {

                r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);

	        //Removing any particles that hit the planet's surface (i.e pass a certain boundary)
	        //In such case the particle is ejected from the orbit around the planet, it's velocity is set so that it is well above the escape velocity of any most planets

                if(r[i] < radius)
                {
                    x[i] = 0.1;
                    y[i] = 0.0;
	            vx[i] = 1E20;
		    vy[i] = 0.0;
	        }
	        else
	        {
                    r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);
                    vx[i+1] = vx[i] - 0.5 * dt * (x[i]/r[i]) * ((G*mass)/(x[i]*x[i] + y[i]*y[i])) - 0.5 * dt * (xmoon[i]/rmoon[i]) * ((G*moomass)/(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]));
                    x[i+1] = x[i] + dt * vx[i+1];

                    r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);
                    vy[i+1] = vy[i] - 0.5 * dt * (y[i]/r[i]) * ((G*mass)/(x[i]*x[i] + y[i]*y[i])) - 0.5 * dt * (xmoon[i]/rmoon[i]) * ((G*moomass)/(xmoon[i]*xmoon[i] + ymoon[i]*ymoon[i]));
                    y[i+1] = y[i] + dt * vy[i+1];
                }
            }

            xpart[k] = x[i];
            ypart[k] = y[i];
            vxpart[k] = vx[i];
            vypart[k] = vy[i];

        }
    }

    //How long this program took to run

    clock_t toc = clock();
    printf("Elapsed time is %f seconds \n", (double)(toc - tic)/ CLOCKS_PER_SEC);

    //Plotting the results

    if (!cpgopen("/XWINDOW")) return 1;
    cpgenv(-1E9,1E9,-1E9,1E9,0,1);
    cpglab("X-Component (m)", "Y-Component (m)", "Point Objects Orbiting a Central Mass Modelling Planetary Rings");
    cpgsci(3);
    cpgpt(nparticles, xpart, ypart, -1);
    cpgsci(4);
    cpgline(nsteps, xmoon, ymoon);
    cpgclos();

    return 0;

}
