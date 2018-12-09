#include "KDTree.h"
#include <math.h>

KDNode::KDNode(double lat, double lon, const char *desc) {
    left = NULL;
    right = NULL;
    description = desc;
    latitude = lat;
    longitude = lon;
}

KDNode::~KDNode() {
}

// returns the distance (in miles) beween this node and a given lat and lon
double KDNode::distance(double lat, double lon) {
    double param = M_PI / 180.0; // required for conversion from degrees to radians
    double rad = 3956.0;  // radius of earth in miles
    double d_lat = (lat - latitude) * param;
    double d_lon = (lon - longitude) * param;
    double dist = sin(d_lat/2) * sin(d_lat/2) + cos(latitude*param) * cos(lat*param) * sin(d_lon/2) * sin(d_lon/2);
    dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
    return rad * dist;
}

KDTree::KDTree() {
    root = NULL;
    size = 0;
}

KDTree::~KDTree() {
    destroy(root);
}

void KDTree::destroy(KDNode *p) {
    if(!p){
        return;
    }
    destroy(p->left);
    destroy(p->right);
    delete(p);
    return;
}


void KDTree::insert(double lat, double lon, const char *desc) {
    KDNode p(lat,lon,desc);
    insert(p,root);
}
bool KDTree::insert(KDNode* p, KDNode* r){
    if(!r){
        return true;
    }

    if(r->depth%2==0){
        if( p->latitude < r->latitude){
            if(insert(p,r->left)){
                r->left=p;
                return false;
            }
        }
        else{
            if(insert(p,r->right)){
                r->right=p;
                return false;
            }
        }
    }
    else{
        if( p->longitude < r->longitude){
            if(insert(p,r->left)){
                r->left=p;
                return false;
            }
        }
        else{
            if(insert(p,r->right)){
                r->right=p;
                return false;
        }
    }
}

unsigned int KDTree::printNeighbors(double lat, double lon, double rad, const char *filter) {
    // ********************************
    // TODO
    // ********************************
    return -1;
}

unsigned int KDTree::getSize() {
    return size;
}
