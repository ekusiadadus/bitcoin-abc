// Copyright (c) 2020 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_AVALANCHE_TEST_UTIL_H
#define BITCOIN_AVALANCHE_TEST_UTIL_H

#include <avalanche/proof.h>
#include <avalanche/proofbuilder.h>
#include <key.h>

#include <cstdio>

namespace avalanche {

constexpr uint32_t MIN_VALID_PROOF_SCORE = 100 * PROOF_DUST_THRESHOLD / COIN;

ProofRef buildRandomProof(CChainState &active_chainstate, uint32_t score,
                          int height = 100,
                          const CKey &masterKey = CKey::MakeCompressedKey());

bool hasDustStake(const ProofRef &proof);

struct TestProofBuilder {
    static ProofId getReverseOrderProofId(ProofBuilder &pb);
    static ProofRef buildWithReversedOrderStakes(ProofBuilder &pb);
    static ProofId getDuplicatedStakeProofId(ProofBuilder &pb);
    static ProofRef buildDuplicatedStakes(ProofBuilder &pb);
};

} // namespace avalanche

#endif // BITCOIN_AVALANCHE_TEST_UTIL_H
