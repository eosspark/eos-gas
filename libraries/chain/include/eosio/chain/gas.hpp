//
// Created by 超超 on 2018/9/14.
//


#pragma once

#include <eosio/chain/types.hpp>
#include <eosio/chain/asset.hpp>

namespace eosio { namespace chain {

		  struct gas_param {
		  public:
				account_name name;
				asset gas;
				account_name producer;
		  };
} }

FC_REFLECT(eosio::chain::gas_param, (name)(gas)(producer))