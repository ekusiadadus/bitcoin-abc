import React from 'react';
import renderer from 'react-test-renderer';
import { ThemeProvider } from 'styled-components';
import { theme } from 'assets/styles/theme';
import CreateTokenForm from 'components/Tokens/CreateTokenForm';
import BCHJS from '@psf/bch-js';
import useBCH from 'hooks/useBCH';
import { walletWithBalancesAndTokensWithCorrectState } from '../../Home/__mocks__/walletAndBalancesMock';
import { WalletContext } from 'utils/context';

beforeEach(() => {
    // Mock method not implemented in JSDOM
    // See reference at https://jestjs.io/docs/manual-mocks#mocking-methods-which-are-not-implemented-in-jsdom
    Object.defineProperty(window, 'matchMedia', {
        writable: true,
        value: jest.fn().mockImplementation(query => ({
            matches: false,
            media: query,
            onchange: null,
            addListener: jest.fn(), // Deprecated
            removeListener: jest.fn(), // Deprecated
            addEventListener: jest.fn(),
            removeEventListener: jest.fn(),
            dispatchEvent: jest.fn(),
        })),
    });
});

test('Wallet with BCH balances and tokens and state field', () => {
    const testBCH = new BCHJS();
    const { getRestUrl, createToken } = useBCH();
    const component = renderer.create(
        <WalletContext.Provider
            value={walletWithBalancesAndTokensWithCorrectState}
        >
            <ThemeProvider theme={theme}>
                <CreateTokenForm
                    BCH={testBCH}
                    getRestUrl={getRestUrl}
                    createToken={createToken}
                    disabled={
                        walletWithBalancesAndTokensWithCorrectState.wallet.state
                            .balances.totalBalanceInSatoshis < 546
                    }
                />
            </ThemeProvider>
        </WalletContext.Provider>,
    );
    let tree = component.toJSON();
    expect(tree).toMatchSnapshot();
});
