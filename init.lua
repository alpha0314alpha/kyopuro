vim.notify("INIT.LUA LOADED", vim.log.levels.INFO)

-- 基本設定
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.mouse = "a"
vim.opt.encoding = "utf-8"
vim.opt.expandtab = true
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4
vim.opt.softtabstop = 4
vim.opt.ignorecase = true
vim.opt.smartcase = true
vim.opt.hlsearch = true
vim.opt.incsearch = true
vim.opt.scrolloff = 5
vim.opt.updatetime = 300
vim.opt.signcolumn = "yes"
vim.opt.termguicolors = true
vim.opt.background = "dark"
vim.opt.formatoptions:remove({ "c", "r", "o" })
vim.opt.backspace = { "indent", "eol", "start" }
vim.g.mapleader = " "

-- キーマップ
vim.keymap.set("n", "<leader>w", ":w<CR>")
vim.keymap.set("n", "<leader>q", ":q<CR>")
vim.keymap.set("n", "<Tab>", ">>")
vim.keymap.set("n", "<S-Tab>", "<<")
vim.keymap.set("i", "<S-Tab>", "<C-d>")
vim.keymap.set("n", "<leader>e", ":NvimTreeToggle<CR>")
vim.keymap.set("n", "<C-p>", "<cmd>Telescope find_files<CR>")
vim.keymap.set("n", "<C-c>", 'ggVG"*yG')
vim.keymap.set("n", "<leader>cs", ":colorscheme", { noremap=true })

-- マウスホイール完全無効
vim.keymap.set({ "n", "i", "v" }, "<ScrollWheelUp>", "<Nop>")
vim.keymap.set({ "n", "i", "v" }, "<ScrollWheelDown>", "<Nop>")
vim.keymap.set({ "n", "i", "v" }, "<ScrollWheelLeft>", "<Nop>")
vim.keymap.set({ "n", "i", "v" }, "<ScrollWheelRight>", "<Nop>")

-- lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
    vim.fn.system({
        "git",
        "clone",
        "https://github.com/folke/lazy.nvim.git",
        lazypath,
    })
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
    rocks = { enabled = false },

    -- カラースキーム
    { "folke/tokyonight.nvim", lazy = false, priority = 1000, },
    { "catppuccin/nvim", name = "catppuccin", lazy = false, priority = 1000, },
    { "rebelot/kanagawa.nvim", lazy = false, priority = 1000, },
    { "dracula/vim", lazy = false, priority = 1000 },
    { "tanvirtin/monokai.nvim", lazy = false, priority = 1000 },
    { "sainnhe/everforest", lazy = false, priority = 1000 },
    { "morhetz/gruvbox", lazy = false, priority = 1000 },
    { "joshdick/onedark.vim", lazy = false, priority = 1000 },
    { "arcticicestudio/nord-vim", lazy = false, priority = 1000 },
    { "tomasr/molokai", lazy = false, priority = 1000 },
    { "ayu-theme/ayu-vim", lazy = false, priority = 1000 },
    { "nlknguyen/papercolor-theme", lazy = false, priority = 1000 },
    { "drewtempelmeyer/palenight.vim", lazy = false, priority = 1000 },
    { "sainnhe/sonokai", lazy = false, priority = 1000 },
    { "nyoom-engineering/oxocarbon.nvim", lazy = false, priority = 1000 },
    { "mofiqul/vscode.nvim", lazy = false, priority = 1000 },
    { "marko-cerovac/material.nvim", lazy = false, priority = 1000 },
    { "oxfist/night-owl.nvim", lazy = false, priority = 1000 },
    { "slugbyte/lackluster.nvim", lazy = false, priority = 1000 },
    { "jeffkreeftmeijer/vim-dim", lazy = false, priority = 1000 },
    { "bluz71/vim-moonfly-colors", lazy = false, priority = 1000 },
    { "bluz71/vim-nightfly-colors", lazy = false, priority = 1000 },
    { "fenetikm/falcon", lazy = false, priority = 1000 },
    { "uloco/bluloco.nvim", lazy = false, priority = 1000 },
    { "olivercederborg/poimandres.nvim", lazy = false, priority = 1000 },
    { "maxmx03/fluoromachine.nvim", lazy = false, priority = 1000 },
    { "lunarvim/darkplus.nvim", lazy = false, priority = 1000 },
    { "loctvl842/monokai-pro.nvim", lazy = false, priority = 1000 },
    { "wadackel/vim-dogrun", lazy = false, priority = 1000 },
    { "masisz/ashikaga.nvim", lazy = false, priority = 1000 },
    { "rafamadriz/neon", lazy = false, priority = 1000 },
    { "frenzyexists/aquarium-vim", lazy = false, priority = 1000 },
    { "cocopon/iceberg.vim", lazy = false, priority = 1000 },
    { "Mitch1000/backpack.nvim", lazy = false, priority = 1000 },
    { "EdenEast/nightfox.nvim", lazy = false, priority = 1000 },
    { "masisz/wisteria.nvim", lazy = false, priority = 1000 },
    { "tiagovla/tokyodark.nvim", lazy = false, priority = 1000 },
    { "altercation/vim-colors-solarized", lazy=false, priority=1000 },
    { "takk8is/green-monochrome-monitor-crt-phosphor-theme-for-zed", lazy=false, priority = 1000},
    { "ofirgall/ofirkai.nvim", lazy=false, priority=1000 },
    { "polirritmico/monokai-nightasty.nvim", lazy=false, priority=1000 },
    { "nyoom-engineering/oxocarbon.nvim", lazy=false, priority=1000 },
    { "rose-pine/neovim", lazy=false, priority=1000},
    { "GlennLeo/cobalt2", lazt=false, priority=1000 },
    { "vim-scripts/Spacegray.vim", lazy=false, priority=1000},
    { "afair/vibrantink2", lazy=false, priority=1000 },

    {
        "projekt0n/github-nvim-theme",
        lazy = false,
        priority = 1000,
        config = function()
            require("github-theme").setup({
                options = {
                    compile_path = vim.fn.stdpath("cache") .. "/github-theme",
                    compile_file_suffix = "_compiled",
                },
            })
            vim.cmd.colorscheme("github_dark_dimmed")
        end,
    },

    -- ui / 編集補助
    { "nvim-tree/nvim-tree.lua" },
    { "nvim-lualine/lualine.nvim" },
    { "hiphish/rainbow-delimiters.nvim" },
    { "tpope/vim-surround" },
    
    {
        "alvan/vim-closetag",
        ft = { "html", "javascriptreact", "typescriptreact"},
    },

    {
        "windwp/nvim-autopairs",
        event = "insertenter",
        config = function()
            require("nvim-autopairs").setup({})
        end,
    },

    {
        "lukas-reineke/indent-blankline.nvim",
        main = "ibl",
        opts = {},
    },

    -- hop.nvim
    {
        "phaazon/hop.nvim",
        branch = "v2",
        config = function()
            require("hop").setup({})
        end,
    },

    -- which-key.nvim
    {
        "folke/which-key.nvim",
        event = "VimEnter",
        config = function()
            local wk = require("which-key")
            wk.register({
                ["<leader>f"] = { name = "file" },
                ["<leader>ff"] = { "<cmd>Telescope find_files<cr>", desc = "find file" },
                ["<leader>fr"] = { "<cmd>Telescope oldfiles<cr>", desc = "recent files" },

                ["<leader>g"] = { name = "git" },
                ["<leader>gb"] = { "<cmd>Gitsigns blame_line<cr>", desc = "blame line" },
                ["<leader>gs"] = { "<cmd>Git<cr>", desc = "status" },

                ["<leader>s"] = { name = "search" },
                ["<leader>sg"] = { "<cmd>Telescope live_grep<cr>", desc = "live grep" },
            })
        end
    },

	-- nvim-cmp
	{ "hrsh7th/nvim-cmp", },
	{ "hrsh7th/cmp-nvim-lsp", },
	{ "hrsh7th/cmp-buffer", },
    { "hrsh7th/cmp-path", },
	{ "saadparwaiz1/cmp_luasnip", },

	{
        "nvim-telescope/telescope.nvim",
        dependencies = { "nvim-lua/plenary.nvim" },
	},
    -- {
    --     "nvim-telescope/telescope-fzf-native.nvim",
    --     build = "make",
    -- },

	{ "tpope/vim-fugitive" },
	{ "lewis6991/gitsigns.nvim", config = true },


    -- luasnip
    {
        "l3mon4d3/luasnip",
        version = "v2.*",
        -- build = "make install_jsregexp",
    },
    {
        "rafamadriz/friendly-snippets",
        dependencies = "l3mon4d3/luasnip",
    },

    -- js
    { "pangloss/vim-javascript" },
    { "maxmellon/vim-jsx-pretty" },
    { "numtostr/comment.nvim", config = true },

    -- coc.nvim
    -- { "neoclide/coc.nvim", branch = "release" },
})

-- autocmd
vim.api.nvim_create_autocmd("FileType", {
    pattern = { "javascript", "jsx", "typescript", "tsx" },
    callback = function()
        vim.opt_local.expandtab = true
    end,
})

-- telescope
require("telescope").setup({})
-- require("telescope").load_extension("fzf")

-- nvim-tree
require("nvim-tree").setup({})

-- hop キーマップ
local hop = require("hop")
local directions = require("hop.hint").HintDirection

vim.keymap.set("n", "<leader>f", function()
hop.hint_char1({ direction = directions.AFTER_CURSOR })
end, { remap = true })

vim.keymap.set("n", "<leader>F", function()
hop.hint_char1({ direction = directions.BEFORE_CURSOR })
end, { remap = true })

-- スニペット
local ls = require("luasnip")
local cmp = require("cmp")

cmp.setup({
    snippet = {
        expand = function(args)
            require("luasnip").lsp_expand(args.body)
        end,
    },
    sources = {
        { name = "nvim_lsp" },
        { name = "luasnip" },
        { name = "buffer" },
        { name = "path" },
    },

    mapping = {
        ["<Tab>"] = cmp.mapping(function(fallback)
            if ls.expand_or_jumpable() then
                ls.expand_or_jump()
            elseif cmp.visible() then
                cmp.select_next_item()
            else
                fallback()
            end
        end, { "i", "s" }),
    },
})

local s  = ls.snippet
local t  = ls.text_node
local i  = ls.insert_node

ls.add_snippets("cpp", {
    -- [](){};
    s("lld", {
        t("["),
        i(1),
        t("]("),
        i(2),
        t("){"),
        t({ "", "    " }),
        i(3),
        t({ "", "};" }),
        i(0),
    }),
})

ls.add_snippets("cpp", {
    -- vector<T> A;
    s("vec", {
        t("vector<"),
        i(1, "int"),
        t("> "),
        i(2, "A"),
        t(";"),
        i(0),
    }),
})  

ls.add_snippets("cpp", {
    -- vector<T> A(N);
    s("vecn", {
        t("vector<"),
        i(1, "int"),
        t("> "),
        i(2, "V"),
        t("("),
        i(3, "N"),
        t(");"),
        i(0),
    }),
})

ls.add_snippets("cpp", {
    -- data<T> A;
    s("data", {
        i(1, "vector"),
        t("<"),
        i(2, "T"),
        t("> "),
        i(3, "A"),
        t(";"),
        i(0),
    })
})

-- カラースキームルーレット
local M = {}
math.randomseed(os.time())
local last = nil

function M.spin(filter)
    local schemes = vim.fn.getcompletion("", "color")
    if #schemes == 0 then
        vim.notify("Not Found", vim.log.levels.WARN)
        return
    end

    -- filter
    local pool = {}
    for _, s in ipairs(schemes) do
        if not filter or filter == "" or s:match(filter) then
            table.insert(pool, s)
        end
    end

    if #pool == 0 then
        vim.notify("No match", vim.log.levels.WARN)
        return
    end

    -- avoid same theme twice
    local pick
    repeat
        pick = pool[math.random(#pool)]
    until pick ~= last or #pool == 1

    last = pick

    -- apply safely
    local ok = pcall(vim.cmd.colorscheme, pick)
    if ok then
        vim.notify("🎰 OK " .. pick)
    else
        vim.notify("💥 failed: " .. pick, vim.log.levels.WARN)
    end
end

vim.api.nvim_create_user_command("Roulette", function(opts)
    M.spin(opts.args)
end, {
    nargs = "?"
})

-- auto roulette on startup (消したければここ丸ごと削除)
-- vim.api.nvim_create_autocmd("VimEnter", {
--     callback = function()
--         M.spin("night") -- 全部なら M.spin()
--     end
-- })

vim.cmd.colorscheme("habamax")
return M
