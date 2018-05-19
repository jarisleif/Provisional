//Chess Board, page 38, run on Chrome version 66 (3rd Ed.)

function buildChess(width, height) {
    var string = "\n";
    var writeHash = true;
    for (var lines = 0; lines < height; ++lines) {

        (lines % 2 === 0) ? writeHash = true : writeHash = false;

        for (var count = 0; count < width; ++count) {
            if (writeHash) { string = string + '#'; writeHash = false; }
            else { string = string + ' '; writeHash = true; }
        }
        string = string + '\n';
    }
    return string;
}