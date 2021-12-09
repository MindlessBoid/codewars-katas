int rental_car_cost(int d){
  //assume day >= 0
  return d*40 - (d >= 7 ? 50 
                :d >= 3 ? 20 
                :0);
}