# C2-Week03-Boids
## Run away
![1](https://user-images.githubusercontent.com/119879041/225200782-73aaabbf-3a5f-43dd-bfd6-d5488b17383d.png)  
Video Link: https://ual.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=3d747228-92df-4cc7-b7fa-afc6001a6ee3

Runaway create a scene that fulfills bubbles with tails. The idea is to a child class called BoidLife that record and forms the a tail for the initial Boid. To realize it, the tail particle only have to stay at the position where boid had past and keep the velocity of the boid at that time, basically is the replica of the boid. However, the tail (BoidLife) would have to disappear after certain time and I want to add a size decay for the tail, so that the tail would be more beautiful, which differ their behavior from the Boid class.  

![1](https://user-images.githubusercontent.com/119879041/225200830-99c22dac-9f9c-4ae7-bb5c-520a68eff787.png)
