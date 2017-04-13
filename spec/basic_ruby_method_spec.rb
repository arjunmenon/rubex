require 'spec_helper'
include Rubex::AST

describe Rubex do
  test_case = 'basic_ruby_method'

  context "Case : #{test_case}" do
    before do
      @path = "#{Dir.pwd}/spec/fixtures/#{test_case}/#{test_case}"
    end

    context ".ast" do
      it "returns a valid Abstract Syntax Tree" do
        t = Rubex.ast @path + ".rubex"
      end
    end

    context ".compile" do
      it "generates valid C code" do
        t, c, e = Rubex.compile @path + ".rubex", test: true
      end
    end

    context "Black Box testing", focus: true do
      it "compiles and checks for valid output" do
        dir = "#{Dir.pwd}/spec/fixtures/#{test_case}"
        setup_and_teardown_compiled_files(test_case, @path, dir) do
          require_relative "#{dir}/#{test_case}.so"
          expect(addition(4,5)).to eq(9)
        end
      end
    end
  end
end
