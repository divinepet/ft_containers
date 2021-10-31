#pragma once

/********************************************************************************************************************/
/*							Change templates to correct names			            							  	*/
/*							you are using in code (most often difference in first letter) 						  	*/
/*							EXAMPLE: FROM ft::enable_if TO ft::Enable_if											*/

#include 					"../Vector.hpp"
#include 					"../Utility.hpp"
#include 					"../Stack.hpp"
#include 					"../Map.hpp"
#include 					"../Set.hpp"
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_map	 			ft::Map
#define	_vector 			ft::Vector
#define	_stack	 			ft::Stack
#define	_set	 			ft::Set
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal
#define _exec_name 			"test1"
/********************************************************************************************************************/