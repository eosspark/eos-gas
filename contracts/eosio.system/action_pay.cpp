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

		 auto fee = gas;
		 fee.amount = (fee.amount + 199) / 200; /// 0.5% fee (round up)

		 auto gas_after_fee = gas;
		 gas_after_fee.amount -= fee.amount;


		 if (payer != producer) {
			 INLINE_ACTION_SENDER(eosio::token, transfer)(N(eosio.token), {payer, N(active)},
																		 {payer, producer, gas_after_fee, std::string("pay gas")});
		 }

		 if( fee.amount > 0 ) {
			 INLINE_ACTION_SENDER(eosio::token, transfer)(N(eosio.token), {payer, N(active)},
																		 {payer, N(eosio.gas), fee, std::string("gas fee")});
		 }
	 }

}

