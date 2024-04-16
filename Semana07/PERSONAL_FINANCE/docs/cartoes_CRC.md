| Classe: `GerenciaCarteiras`||
| :------------------------ | -------------------- |
| **Responsabilidades**     | **Colaborações**     |
| carteiras                 | `Carteira`          |
|

| Classe: `Carteira`||
| :------------------------ | -------------------- |
| **Responsabilidades**     | **Colaborações**     |
| nome                      | `Transação`          |
| saldoAtual                | `CarteiraBancaria`   |
|                           |                      |

| Classe: `CarteiraBancaria`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| cartoesCredito         | `CartaoDeCredito`    |

| Classe: `Transacao`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| ID                     |  `Carteira`          |
| data                   |                      |
| valor                  |                      |
| categoria              |                      |
| imprimirInfo           |                      |

| Classe: `Despesas`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| carteira               | `Transacao`          |
|                        | `CartaoDeCredito`    |

| Classe: `Receita`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| carteira               | `Transacao`          |

| Classe: `Transferencia`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| origem                 | `Transacao`          |
| destino                |                      |

| Classe: `CartaoDeCredito`||
| :--------------------- | -------------------- |
| **Responsabilidades:** | **Colaborações:**    |
| nome                   | `CarteiraBancaria`   |
| numero                 |                      |
| CVV                    |                      |
| fechmento              |                      |
| limite                 |                      |
| despesas               |                      |


