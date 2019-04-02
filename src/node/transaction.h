// Copyright (c) 2017-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NODE_TRANSACTION_H
#define BITCOIN_NODE_TRANSACTION_H

#include <primitives/transaction.h>
#include <util/error.h>

class Config;
struct TxId;

/**
 * Broadcast a transaction
 *
 * @param[in]  tx the transaction to broadcast
 * @param[out] &txid the txid of the transaction, if successfully broadcast
 * @param[out] &error reference to UniValue to fill with error info on failure
 * @param[out] &err_string reference to std::string to fill with error string if
 * available
 * @param[in]  allowhighfees whether to allow fees exceeding maxTxFee
 * return true on success, false on error (and fills in `error`)
 */
bool BroadcastTransaction(const Config &config, CTransactionRef tx, TxId &txid,
                          TransactionError &error, std::string &err_string,
                          bool allowhighfees = false);

#endif // BITCOIN_NODE_TRANSACTION_H
