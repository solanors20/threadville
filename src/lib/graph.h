#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

#include "node.h"
#include "threadville.h"
#include "dijkstra.h"
#include "constants.h"
#include "bridge.h"
#include "map.h"

struct NODE* linkedList;

THREADVILLE* threadville;

BRIDGE *larry, *joe, *curly, *shemp, *moe;

int highwayWeight = 1;
int regularPathWeight = 10;

int weights[VERTEXES][VERTEXES];

char ch_arr[VERTEXES][6] = {"A1", "A2", "B1", "B2", "C1", "C2", "D1", "D2", "E1", "E2", "F1", "F2",
                            "A8", "A3", "B8", "B3", "C8", "C3", "D8", "D3", "E3", "E8", "F8", "F3",
                            "A7", "A4", "B7", "B4", "C7", "C4", "D7", "D4", "E7", "E4", "F7", "F4",
                            "A6G1", "A5G2", "B6H1", "B5H2", "C6I1", "C5I2", "D6J1", "D5J2", "E6K1", "E5K2", "F6L1", "F5L2",
                            "G6", "G3", "H6", "H3", "I6", "I3", "J6", "J3", "K6", "K3", "L6", "L3",
                            "G5", "G4", "H5", "H4", "I5", "I4", "J5", "J4", "K5", "K4", "L5", "L4",
                            "Y8", "Y1", "Y2", "BG4", "BH5", "BH4", "BI5", "BI4", "BJ5", "BJ4", "BK5", "BK4", "BL5", "Z2", "Z1", "Z8",
                            "Y3", "Z3",
                            "Y4", "Z4",
                            "Y7", "Y6", "Y5", "BM2", "BN1", "BN2", "BO1", "BO2", "BP1", "BP2", "BQ1", "BQ2", "BR1", "Z5", "Z6", "Z7",
                            "M1", "M2", "N1", "N2", "O1", "O2", "P1", "P2", "Q1", "Q2", "R1", "R2",
                            "M6", "M3", "N6", "N3", "O6", "O3", "P6", "P3", "Q6", "Q3", "R6", "R3",
                            "M5S1", "M4S2", "N5T1", "N4T2", "O5U1", "O4U2", "P5V1", "P4V2", "Q5W1", "Q4W2", "R5X1", "R4X2",
                            "S8", "S3", "T8", "T3", "U8", "U3", "V8", "V3", "W8", "W3", "X8", "X3",
                            "S7", "S4", "T7", "T4", "U7", "U4", "V7", "V4", "W7", "W4", "X7", "X7",
                            "S6", "S5", "T6", "T5", "U6", "U5", "V6", "V5", "W6", "W5", "X6", "X5"
                           };

// Initializes the linked list
void initLinkedList()
{
    linkedList = malloc(VERTEXES * sizeof(struct NODE));
}

void addNode (NODE* node, int position)
{
    linkedList[position] = *node;
}

void fillLinkedList()
{
    for(int i=0; i<VERTEXES; i++)
    {
        addNode(createNode(i, ch_arr[i], 2), i);
    }
}

void linkNodes (int index, int nextNode1, int nextNode2, int nextNode3, NODE* linkedList)
{
    if(nextNode1 != -1) 
    {
        linkedList[index].nextNode1 = &linkedList [nextNode1];
    }
    else
    {
        linkedList[index].nextNode1 = NULL;
    }
    if(nextNode2 != -1) 
    {
        linkedList[index].nextNode2 = &linkedList [nextNode2];
    }
    else 
    {
        linkedList[index].nextNode2 = NULL;
    }
    if(nextNode3 != -1) 
    {
        linkedList[index].nextNode3 = &linkedList[nextNode3];
    }
    else 
    {
        linkedList[index].nextNode3 = NULL;
    }
}

void setNextLink() 
{
    linkNodes(0, 1, -1, -1, linkedList); // nodeA1
    linkNodes(1, 2, 13, -1, linkedList); // nodeA2
    linkNodes(2, 3, -1, -1, linkedList); // nodeB1
    linkNodes(3, 4, 15, -1, linkedList); // nodeB2
    linkNodes(4, 5, -1, -1, linkedList); // nodeC1
    linkNodes(5, 6, 17, -1, linkedList); // nodeC2
    linkNodes(6, 7, -1, -1, linkedList); // nodeD1
    linkNodes(7, 8, 19, -1, linkedList); // nodeD2
    linkNodes(8, 9, -1, -1, linkedList); // nodeE1
    linkNodes(9, 10, 21, -1, linkedList); // nodeE2
    linkNodes(10, 11, -1, -1, linkedList); // nodeF1
    linkNodes(11, 23, -1, -1, linkedList); // nodeF2
    linkNodes(12, 0, -1, -1, linkedList); // nodeA8
    linkNodes(13, 25, -1, -1, linkedList); // nodeA3
    linkNodes(14, 2, -1, -1, linkedList); // nodeB8
    linkNodes(15, 27, -1, -1, linkedList); // nodeB3
    linkNodes(16, 4, -1, -1, linkedList); // nodeC8
    linkNodes(17, 29, -1, -1, linkedList); // nodeC3
    linkNodes(18, 6, -1, -1, linkedList); // nodeD8
    linkNodes(19, 31, -1, -1, linkedList); // nodeD3
    linkNodes(20, 8, -1, -1, linkedList); // nodeE8
    linkNodes(21, 33, -1, -1, linkedList); // nodeE3
    linkNodes(22, 10, -1, -1, linkedList); // nodeF8
    linkNodes(23, 35, -1, -1, linkedList); // nodeF3
    linkNodes(24, 12, -1, -1, linkedList); // nodeA7
    linkNodes(25, 37, 49, -1, linkedList); // nodeA4
    linkNodes(26, 14, -1, -1, linkedList); // nodeB7
    linkNodes(27, 51, 39, -1, linkedList); // nodeB4
    linkNodes(28, 16, -1, -1, linkedList); // nodeC7
    linkNodes(29, 53, 41, -1, linkedList); // nodeC4
    linkNodes(30, 18, -1, -1, linkedList); // nodeD7
    linkNodes(31, 55, 43, -1, linkedList); // nodeD4
    linkNodes(32, 20, -1, -1, linkedList); // nodeE7
    linkNodes(33, 57, 45, -1, linkedList); // nodeE4
    linkNodes(34, 22, -1, -1, linkedList); // nodeF7
    linkNodes(35, 47, 59, -1, linkedList); // nodeF4
    linkNodes(36, 24, -1, -1, linkedList); // nodeA6G1
    linkNodes(37, 36, -1, -1, linkedList); // nodeA5G2
    linkNodes(38, 37, 26, 49, linkedList); // nodeB6H1
    linkNodes(39, 38, -1, -1, linkedList); // nodeB5H2
    linkNodes(40, 28, 39, 51, linkedList); // nodeC6I1
    linkNodes(41, 40, -1, -1, linkedList); // nodeC5I2
    linkNodes(42, 30, 41, 53, linkedList); // nodeD6J1
    linkNodes(43, 42, -1, -1, linkedList); // nodeD5J2
    linkNodes(44, 32, 43, 55, linkedList); // nodeE6K1
    linkNodes(45, 44, -1, -1, linkedList); // nodeE5K2
    linkNodes(46, 34, 45, 57, linkedList); // nodeF6L1
    linkNodes(47, 46, -1, -1, linkedList); // nodeF5L2
    linkNodes(48, 24, -1, -1, linkedList); // nodeG6
    linkNodes(49, 61, -1, -1, linkedList); // nodeG3
    linkNodes(50, 37, 26, -1, linkedList); // nodeH6
    linkNodes(51, 63, -1, -1, linkedList); // nodeH3
    linkNodes(52, 39, 28, -1, linkedList); // nodeI6
    linkNodes(53, 65, -1, -1, linkedList); // nodeI3
    linkNodes(54, 41, 30, -1, linkedList); // nodeJ6
    linkNodes(55, 67, -1, -1, linkedList); // nodeJ3
    linkNodes(56, 43, 32, -1, linkedList); // nodeK6
    linkNodes(57, 69, -1, -1, linkedList); // nodeK3
    linkNodes(58, 46, 34, -1, linkedList); // nodeL6
    linkNodes(59, 71, -1, -1, linkedList); // nodeL3
    linkNodes(60, 48, -1, -1, linkedList); // nodeG5
    linkNodes(61, 75, -1, -1, linkedList); // nodeG4
    linkNodes(62, 50, -1, -1, linkedList); // nodeH5
    linkNodes(63, 77, -1, -1, linkedList); // nodeH4
    linkNodes(64, 52, -1, -1, linkedList); // nodeI5
    linkNodes(65, 79, -1, -1, linkedList); // nodeI4
    linkNodes(66, 54, -1, -1, linkedList); // nodeJ5
    linkNodes(67, 81, -1, -1, linkedList); // nodeJ4
    linkNodes(68, 56, -1, -1, linkedList); // nodeK5
    linkNodes(69, 83, -1, -1, linkedList); // nodeK4
    linkNodes(70, 58, -1, -1, linkedList); // nodeL5
    linkNodes(71, 85, -1, -1, linkedList); // nodeL4
    linkNodes(72, 92, -1, -1, linkedList); // nodeY8
    linkNodes(73, 72, -1, -1, linkedList); // nodeY1
    linkNodes(74, 60, 73, -1, linkedList); // nodeY2 -> it will be the head node
    linkNodes(75, 95, -1, -1, linkedList); // nodeBG4
    linkNodes(76, 62, -1, -1, linkedList); // nodeBH5
    linkNodes(77, 97, -1, -1, linkedList); // nodeBH4
    linkNodes(78, 64, -1, -1, linkedList); // nodeBI5
    linkNodes(79, 99, -1, -1, linkedList); // nodeBI4
    linkNodes(80, 66, -1, -1, linkedList); // nodeBJ5
    linkNodes(81, 101, -1, -1, linkedList); // nodeBJ4
    linkNodes(82, 68, -1, -1, linkedList); // nodeBK5
    linkNodes(83, 103, -1, -1, linkedList); // nodeBK4
    linkNodes(84, 70, -1, -1, linkedList); // nodeBL5
    linkNodes(85, 74, 89, -1, linkedList); // nodeZ2
    linkNodes(86, 85, -1, -1, linkedList); // nodeZ1
    linkNodes(87, 86, -1, -1, linkedList); // nodeZ8
    linkNodes(88, 74, -1, -1, linkedList); // nodeY3
    linkNodes(89, 88, 91, -1, linkedList); // nodeZ3
    linkNodes(90, 88, 91, -1, linkedList); // nodeY4
    linkNodes(91, 105, -1, -1, linkedList); // nodeZ4
    linkNodes(92, 93, -1, -1, linkedList); // nodeY7
    linkNodes(93, 94, -1, -1, linkedList); // nodeY6
    linkNodes(94, 90, 105, -1, linkedList); // nodeY5
    linkNodes(95, 109, -1, -1, linkedList); // nodeBM2
    linkNodes(96, 76, -1, -1, linkedList); // nodeBN1
    linkNodes(97, 111, -1, -1, linkedList); // nodeBN2
    linkNodes(98, 78, -1, -1, linkedList); // nodeBO1
    linkNodes(99, 113, -1, -1, linkedList); // nodeBO2
    linkNodes(100, 80, -1, -1, linkedList); // nodeBP1
    linkNodes(101, 115, -1, -1, linkedList); // nodeBP2
    linkNodes(102, 82, -1, -1, linkedList); // nodeBQ1
    linkNodes(103, 117, -1, -1, linkedList); // nodeBQ2
    linkNodes(104, 84, -1, -1, linkedList); // nodeBR1
    linkNodes(105, 119, 106, -1, linkedList); // nodeZ5
    linkNodes(106, 107, -1, -1, linkedList); // nodeZ6
    linkNodes(107, 87, -1, -1, linkedList); // nodeZ7
    linkNodes(108, 94, -1, -1, linkedList); // nodeM1
    linkNodes(109, 121, -1, -1, linkedList); // nodeM2
    linkNodes(110, 96, -1, -1, linkedList); // nodeN1
    linkNodes(111, 123, -1, -1, linkedList); // nodeN2
    linkNodes(112, 98, -1, -1, linkedList); // nodeO1
    linkNodes(113, 125, -1, -1, linkedList); // nodeO2
    linkNodes(114, 100, -1, -1, linkedList); // nodeP1
    linkNodes(115, 127, -1, -1, linkedList); // nodeP2
    linkNodes(116, 102, -1, -1, linkedList); // nodeQ1
    linkNodes(117, 129, -1, -1, linkedList); // nodeQ2
    linkNodes(118, 104, -1, -1, linkedList); // nodeR1
    linkNodes(119, 131, -1, -1, linkedList); // nodeR2
    linkNodes(120, 108, -1, -1, linkedList); // nodeM6
    linkNodes(121, 145, 134, -1, linkedList); // nodeM3
    linkNodes(122, 110, -1, -1, linkedList); // nodeN6
    linkNodes(123, 147, 136, -1, linkedList); // nodeN3
    linkNodes(124, 112, -1, -1, linkedList); // nodeO6
    linkNodes(125, 149, 138, -1, linkedList); // node03
    linkNodes(126, 114, -1, -1, linkedList); // nodeP6
    linkNodes(127, 151, 140, -1, linkedList); // nodeP3
    linkNodes(128, 116, -1, -1, linkedList); // nodeQ6
    linkNodes(129, 142, 153, -1, linkedList); // nodeQ3
    linkNodes(130, 118, -1, -1, linkedList); // nodeR6
    linkNodes(131, 155, -1, -1, linkedList); // nodeR3
    linkNodes(132, 133, -1, -1, linkedList); // nodeM5S1
    linkNodes(133, 134, 145, 122, linkedList); // nodeM4S2
    linkNodes(134, 135, -1, -1, linkedList); // nodeN5T1
    linkNodes(135, 136, 147, 124, linkedList); // nodeN4T2
    linkNodes(136, 137, -1, -1, linkedList); // nodeO5U1
    linkNodes(137, 138, 149, 126, linkedList); // nodeO4U2
    linkNodes(138, 139, -1, -1, linkedList); // nodeP5V1
    linkNodes(139, 140, 151, 128, linkedList); // nodeP4V2
    linkNodes(140, 141, -1, -1, linkedList); // nodeQ5W1
    linkNodes(141, 142, 153, 130, linkedList); // nodeQ4W2
    linkNodes(142, 143, -1, -1, linkedList); // nodeR5X1
    linkNodes(143, 155, -1, -1, linkedList); // nodeR4X2
    linkNodes(144, 132, 120, -1, linkedList); // nodeS8
    linkNodes(145, 157, -1, -1, linkedList); // nodeS3
    linkNodes(146, 134, 122, -1, linkedList); // nodeT8
    linkNodes(147, 159, -1, -1, linkedList); // nodeT3
    linkNodes(148, 136, 124, -1, linkedList); // nodeU8
    linkNodes(149, 161, -1, -1, linkedList); // nodeU3
    linkNodes(150, 138, 126, -1, linkedList); // nodeV8
    linkNodes(151, 163, -1, -1, linkedList); // nodeV3
    linkNodes(152, 140, 128, -1, linkedList); // nodeW8
    linkNodes(153, 165, -1, -1, linkedList); // nodeW3
    linkNodes(154, 142, 130, -1, linkedList); // nodeX8
    linkNodes(155, 167, -1, -1, linkedList); // nodeX3
    linkNodes(156, 144, -1, -1, linkedList); // nodeS7
    linkNodes(157, 169, -1, -1, linkedList); // nodeS4
    linkNodes(158, 146, -1, -1, linkedList); // nodeT7
    linkNodes(159, 171, -1, -1, linkedList); // nodeT4
    linkNodes(160, 148, -1, -1, linkedList); // nodeU7
    linkNodes(161, 173, -1, -1, linkedList); // nodeU4
    linkNodes(162, 150, -1, -1, linkedList); // nodeV7
    linkNodes(163, 175, -1, -1, linkedList); // nodeV4
    linkNodes(164, 152, -1, -1, linkedList); // nodeW7
    linkNodes(165, 177, -1, -1, linkedList); // nodeW4
    linkNodes(166, 154, -1, -1, linkedList); // nodeX7
    linkNodes(167, 179, -1, -1, linkedList); // nodeX4
    linkNodes(168, 156, -1, -1, linkedList); // nodeS6
    linkNodes(169, 168, -1, -1, linkedList); // nodeS5
    linkNodes(170, 169, 158, -1, linkedList); // nodeT6
    linkNodes(171, 170, -1, -1, linkedList); // nodeT5
    linkNodes(172, 171, 160, -1, linkedList); // nodeU6
    linkNodes(173, 172, -1, -1, linkedList); // nodeU5
    linkNodes(174, 173, 162, -1, linkedList); // nodeV6
    linkNodes(175, 174, -1, -1, linkedList); // nodeV5
    linkNodes(176, 175, 164, -1, linkedList); // nodeW6
    linkNodes(177, 176, -1, -1, linkedList); // nodeW6
    linkNodes(178, 177, 166, -1, linkedList); // nodeX6
    linkNodes(179, 178, -1, -1, linkedList); // nodeX5

    // Head node of the linked list is assigned to Threadville
    threadville = createThreadville();
    threadville->node = linkedList[74];
}

void createBridges()
{
    larry = createBridge("Larry", linkedList[96].nextNode1, 
                         linkedList[61].nextNode1, linkedList[110].nextNode1, 
                         linkedList[75].nextNode1);
    
    joe = createBridge("Joe", linkedList[104].nextNode1, 
                         linkedList[69].nextNode1, linkedList[118].nextNode1, 
                         linkedList[83].nextNode1);

    curly = createBridge("Curly", linkedList[98].nextNode1, 
                         linkedList[63].nextNode1, linkedList[112].nextNode1, 
                         linkedList[77].nextNode1);

    shemp = createBridge("Shemp", linkedList[102].nextNode1, 
                         linkedList[67].nextNode1, linkedList[116].nextNode1, 
                         linkedList[81].nextNode1);
    
    moe = createBridge("Moe", linkedList[100].nextNode1, 
                         linkedList[65].nextNode1, linkedList[114].nextNode1, 
                         linkedList[79].nextNode1);
}

void setWeightsMatrix()
{
    for(int i = 0; i < VERTEXES; i++)
    {
		for(int j = 0; j < VERTEXES; j++)
        {
			weights[i][j] = 0;
		}
	}

    for (int i = 0; i < VERTEXES; i++)
    {
        for (int j = 0; j < VERTEXES; j++)
        {
            int nextNodeIndex;
            // TO-DO set a higher value for the highway
            if (linkedList[i].nextNode1 != NULL)
            {
                 nextNodeIndex = linkedList[i].nextNode1->id;
                 if (nextNodeIndex == j){
                     weights [i][nextNodeIndex] = regularPathWeight;
                 }
            }
            if (linkedList[i].nextNode2 != NULL)
            {
                nextNodeIndex = linkedList[i].nextNode2->id;
                if (nextNodeIndex == j){
                    weights [i][nextNodeIndex] = regularPathWeight;
                }
            }
            if (linkedList[i].nextNode3 != NULL)
            {
                nextNodeIndex = linkedList[i].nextNode3->id;
                if (nextNodeIndex == j)
                {
                    weights[i][nextNodeIndex] = regularPathWeight;
                }
            }
        }
    }
}

void performDijkstra()
{
    for(int i = 0; i<VERTEXES; i++)
    {
        dijkstra(weights, linkedList[i].id, linkedList[i].paths);
    }
}



void setGraphCoordinatesForGui() 
{
    int i=0;
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLUMNS; y++)
        {
            if(map[x][y] == 5)
            {
                linkedList[i].x = y * TILE_SIZE + 10;
                linkedList[i].y = x * TILE_SIZE;
                i++;
            } 
            else if(map[x][y] == 6)
            {
                linkedList[i].x=y * TILE_SIZE;
                linkedList[i].y=x * TILE_SIZE;
                i++;
            }
            else if(map[x][y] == 8) 
            {
                linkedList[i].x = y * TILE_SIZE + 10;
                linkedList[i].y = x * TILE_SIZE;
                i++;
            }
            else if(map[x][y] == 9)
            {
                linkedList[i].x = y * TILE_SIZE + 10;
                linkedList[i].y = x * TILE_SIZE;
                i++;
            }         
        }
    }
}

#endif