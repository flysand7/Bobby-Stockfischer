
enum PieceColor {
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_CNT,
} typedef PieceColor;

enum PieceKind {
    PIECE_P,
    PIECE_N,
    PIECE_B,
    PIECE_R,
    PIECE_Q,
    PIECE_K,
    PIECE_CNT,
} typedef PieceKind;

static char piece_char_from_kind(PieceKind piece) {
    switch(piece) {
        case PIECE_N: return 'N';
        case PIECE_B: return 'B';
        case PIECE_R: return 'R';
        case PIECE_Q: return 'Q';
        case PIECE_K: return 'K';
        case PIECE_P: return 'P';
        default:      return 0;
    }
}

static char piece_char_from_kind_lower(PieceKind piece) {
    switch(piece) {
        case PIECE_N: return 'n';
        case PIECE_B: return 'b';
        case PIECE_R: return 'r';
        case PIECE_Q: return 'q';
        case PIECE_K: return 'k';
        case PIECE_P: return 'p';
        default:      return 0;
    }
}

static PieceKind piece_kind_from_char(char pn) {
    switch(pn) {
        case 'N': return PIECE_N;
        case 'B': return PIECE_B;
        case 'R': return PIECE_R;
        case 'Q': return PIECE_Q;
        case 'K': return PIECE_K;
        case 'P': return PIECE_P;
        default:      return 0;
    }
}

static PieceKind piece_kind_from_char_lower(char pn) {
    switch(pn) {
        case 'n': return PIECE_N;
        case 'b': return PIECE_B;
        case 'r': return PIECE_R;
        case 'q': return PIECE_Q;
        case 'k': return PIECE_K;
        case 'p': return PIECE_P;
        default:      return 0;
    }
}

