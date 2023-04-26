// Part B
std::map<std::pair<std::string, std::string>, int> partA_remaining_routes = routes;
std::set<std::string> partA_remaining_cities = cities;
std::string partA_current_city = i;
std::string partA_destination;
while(!partA_remaining_cities.empty() && !partA_remaining_routes.empty()) {
int dist_to_dest = 0;
for (auto &j: partA_remaining_routes) {
if ((j.first.first == partA_current_city || j.first.second == partA_current_city) && j.second > dist_to_dest) {
dist_to_dest = j.second;
j.first.first == partA_current_city ? partA_destination = j.first.second : partA_destination = j.first.first;
}
}
partA_remaining_cities.erase(partA_current_city);
for (auto it = partA_remaining_routes.cbegin(); it != partA_remaining_routes.cend(); ){
if (it->first.first == partA_current_city || it->first.second == partA_current_city) {
partA_remaining_routes.erase(it++);
}else{
++it;
}
}
max_distance += dist_to_dest;
partA_current_city = partA_destination;
}