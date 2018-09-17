//
// Created by 超超 on 2018/9/14.
//
#include "eosio.system.hpp"

#include <eosio.token/eosio.token.hpp>

namespace eosiosystem {
	 void system_contract::paygas( account_name payer, asset gas, account_name producer ) {
	 	 using namespace eosio;
	 	 print("pay gas action");

		 require_auth(N(eosio));

		 INLINE_ACTION_SENDER(eosio::token, transfer)( N(eosio.token), {payer,N(active)},
																	  { payer, producer, gas, std::string("pay gas") } );
	 }

}

